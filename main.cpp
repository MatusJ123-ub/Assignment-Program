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
              << "Enter your choice: ";
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
            case 1: {
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter priority (High/Medium/Low): ";
                getline(cin, priority);
                cout << "Enter due date: ";
                getline(cin, dueDate);
                taskList.addTask(description, priority, dueDate);
                break;
            }

            // The rest of the menu implementation here
        }
    }
    return 0;
}