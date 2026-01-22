#ifndef TASK_H
#define TASK_H

#define TITLE_MAX 100
#define TASKS_MAX 1000

typedef struct {
    int id;
    char title[TITLE_MAX];
    int completed;
} Task;

void add_task(Task tasks[], int *task_count, int *next_id);
void list_tasks(const Task tasks[], int task_count);
void mark_task_completed(Task tasks[], int task_count);
void delete_task(Task tasks[], int *task_count);

#endif



