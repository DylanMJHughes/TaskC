#include <stdio.h>
#include "storage.h"

#define TASKS_FILE "data/tasks.dat"

int load_tasks(Task tasks[], int *task_count, int *next_id) {
    FILE *fp = fopen(TASKS_FILE, "rb");
    if (!fp) {
        return 0; // file does not exist
    }

    fread(task_count, sizeof(int), 1, fp);
    fread(next_id, sizeof(int), 1, fp);
    fread(tasks, sizeof(Task), *task_count, fp);

    fclose(fp);
    return 1;
}

void save_tasks(const Task tasks[], int task_count, int next_id) {
    FILE *fp = fopen(TASKS_FILE, "wb");
    if (!fp) {
        perror("Failed to save tasks.\n");
        return;
    }

    fwrite(&task_count, sizeof(int), 1, fp);
    fwrite(&next_id, sizeof(int), 1, fp);
    fwrite(tasks, sizeof(Task), task_count, fp);

    fclose(fp);
}
