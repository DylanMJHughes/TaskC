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

int main(void) {
    Task tasks[TASKS_MAX];
    int task_count = 0;
    int next_id = 1;

    int choice = -1;

    while (choice != 0) {
        print_menu();

       if (scanf("%d", &choice) != 1) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
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
            case 3:
            mark_task_completed(tasks, task_count);
                break;
            case 4:
            delete_task(tasks, &task_count);
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
