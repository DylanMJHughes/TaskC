#include <stdio.h>
#include "task.h"

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
