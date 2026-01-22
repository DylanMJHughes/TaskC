#include <stdio.h>
#include <string.h>
#include "task.h"

static void clear_stdin_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

void list_tasks(const Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks yet.\n");
        return;
    }

    printf("\n--- Tasks (%d) ---\n", task_count);
    for (int i = 0; i < task_count; i++) {
        printf("#%d [%c] %s\n",
               tasks[i].id,
               tasks[i].completed ? 'x' : ' ',
               tasks[i].title);
    }
}

void add_task(Task tasks[], int *task_count, int *next_id) {
    if (*task_count >= TASKS_MAX) {
        printf("Task list is full.\n");
        return;
    }

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
    t.id = (*next_id)++;
    strncpy(t.title, title, TITLE_MAX);
    t.title[TITLE_MAX - 1] = '\0';
    t.completed = 0;

    tasks[*task_count] = t;
    (*task_count)++;

    printf("Added task #%d.\n", t.id);
}

static int find_task_index_by_id(const Task tasks[], int task_count, int id) {
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            return i;
        }
    }
    return -1;
}

void mark_task_completed(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks to mark.\n");
        return;
    }

    int id;
    printf("Enter task ID to mark as completed: ");
    if (scanf("%d", &id) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Invalid input.\n");
        return;
    }

    int index = find_task_index_by_id(tasks, task_count, id);
    if (index == -1) {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    tasks[index].completed = 1;
    printf("Task #%d marked as completed.\n", id);
}

void delete_task(Task tasks[], int *task_count) {
    if (*task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int id;
    printf("Enter task ID to delete: ");
    if (scanf("%d", &id) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Invalid input.\n");
        return;
    }

    int index = find_task_index_by_id(tasks, *task_count, id);
    if (index == -1) {
        printf("Task with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < *task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*task_count)--;

    printf("Task #%d deleted.\n", id);
}

