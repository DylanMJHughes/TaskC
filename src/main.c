// This code is written in C17 standard.
#include <stdio.h>


static void print_menu(void) {
    printf("TaskC\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Mark Task Complete\n");
    printf("4. Delete Task\n");
    printf("0. Save and Exit\n");
    printf("Select an option (1-5): ");
}




int main(void) {
   int choice = -1;

   while (choice !=0) {
        print_menu();

        // input not a number; clear input invalid
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 0 and 4.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1: printf("Add Task selected (not implemented yet).\n"); break;
            case 2: printf("List Tasks selected (not implemented yet).\n"); break;
            case 3: printf("Mark Task Complete selected (not implemented yet).\n"); break;
            case 4: printf("Delete Task selected (not implemented yet).\n"); break;
            case 0: printf("saved and Exiting.\n"); break;
            default: printf("Invalid choice. Please select a number between 0 and 4.\n"); break;
        }
   }
    return 0;
}



