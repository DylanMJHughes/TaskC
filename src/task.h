#ifndef TASK_H
#define TASK_H

#define TITLE_MAX 100
#define TASKS_MAX 1000

typedef struct {
    int id;
    char title[TITLE_MAX];
    int completed; // 0 for incomplete, 1 for completed
} Task;

#endif // TASK_H


