#include "taskList.h"
#include <iostream>
#include <string>

void displayMenu() {
    cout << "\n=== Task Manager Menu ===\n"
              << "1. Add New Task\n"
              << "2. Remove Task\n"
              << "3. Mark Task as Complete\n"
              << "4. Display All Tasks\n"
              << "5. Display Tasks by Priority\n"
              << "6. Search for Task\n"
              << "7. Exit\n"
              << "Enter your choice: "
              << "yes";
}

int main() {
    TaskList taskList;
    int choice;
    string description;
    string priority;
    string dueDate;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter priority (High/Medium/Low): ";
                getline(cin, priority);
                cout << "Enter due date (format: YYYY-MM-DD): ";
                getline(cin, dueDate);
                taskList.addTask(description, priority, dueDate);
                cout << "Task added successfully!\n";
                break;

            case 2:
                cout << "Enter the description of the task to remove: ";
                getline(cin, description);
                taskList.removeTask(description);
                break;

            case 3:
                cout << "Enter the description of the task to mark as complete: ";
                getline(cin, description);
                taskList.markTaskComplete(description);
                break;

            case 4:
                taskList.displayAllTasks();
                break;

            case 5:
                cout << "Enter priority to filter by (High/Medium/Low): ";
                getline(cin, priority);
                taskList.displayByPriority(priority);
                break;

            case 6:
                cout << "Enter the description of the task to search: ";
                getline(cin, description);
                {
                    Task* task = taskList.searchTask(description);
                    if (task) {
                        cout << "\n=== Task Found ===\n"
                             << "Description: " << task->getDescription() << "\n"
                             << "Priority: " << task->getPriority() << "\n"
                             << "Due Date: " << task->getDueDate() << "\n"
                             << "Completion Status: " << (task->getIsComplete() ? "Complete" : "Incomplete") << "\n"; 
                    }else {
                        cout << "task not found.\n";
                    }
                }
                    break; 

        case 7: // Exit
        cout << "Exiting Task Manager. Goodbye!\n";
        return 0;

         default: // Invalid choice
        cout << "Invalid choice. Please try again.\n";
        break;
    }
}

return 0;
}