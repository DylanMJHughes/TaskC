#ifndef STORAGE_H
#define STORAGE_H

#include "task.h"

// load tasks from file 
// reurns 1 on success, 0 on failure
int load_tasks(Task tasks[], int *task_count, int *next_id);

// save tasks to file
void save_tasks(const Task tasks[], int task_count, int next_id);

#endif
