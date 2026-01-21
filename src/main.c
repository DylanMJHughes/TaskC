// This code is written in C17 standard.
#include <stdio.h>
#include <string.h>
#include "task.h"

static void print_menu(void) {
    printf("TaskC\n");
    printf("1) Add Task\n");
    printf("2) List Tasks\n");
    printf("3) Mark Task Completed\n");
    printf("4) Delete Task\n");
    printf("0) Save & Exit\n");
    printf("Choose: ");
}

static void clear_stdin_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

static void add_task(Task tasks[], int *task_count, int *next_id) {
    if (*task_count >= TASKS_MAX) {
        printf("Task list is full.\n");
        return;
    }

    // Clear leftover newline after reading menu choice
    clear_stdin_line();

    char title[TITLE_MAX];
    printf("Enter task title: ");
    if (!fgets(title, sizeof(title), stdin)) {
        printf("Failed to read title.\n");
        return;
    }
    trim_newline(title);

    if (title[0] == '\0') {
        printf("Title cannot be empty.\n");
        return;
    }

    Task t;
    t.id = *next_id;
    (*next_id)++;
    strncpy(t.title, title, TITLE_MAX);
    t.title[TITLE_MAX - 1] = '\0';
    t.completed = 0;

    tasks[*task_count] = t;
    (*task_count)++;

    printf("Added task #%d.\n", t.id);
}

int main(void) {
    Task tasks[TASKS_MAX];
    int task_count = 0;
    int next_id = 1;

    int choice = -1;

    while (choice != 0) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            clear_stdin_line();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                add_task(tasks, &task_count, &next_id);
                break;
            case 2:
                list_tasks(tasks, task_count);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Not implemented yet.\n");
                break;
        }
    }

    return 0;
}
