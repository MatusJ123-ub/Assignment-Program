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
            case 1: {
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter priority (High/Medium/Low): ";
                getline(cin, priority);
                cout << "Enter due date: ";
                getline(cin, dueDate);
                taskList.addTask(description, priority, dueDate);
                break;

                case 2: //remove Task 
                cout << "Enter task to remove: ";
                getline(cin, description);
                taskList.removeTask(description);
                break; 
                

                case 3: //Mark task as complete
                cout << "Enter task to mark as complete";
                getline(cin,description);
                taskList.markTaskComplete(description);
                break;

                case 4: //Display all Tasks
                taskList.displayAllTasks();

                case 5: //Display tasks by priority
                cout << "Enter priority to filter by (High/Medium/Low): ";
                getline(cin, priority);
                taskList.displayByPriority(priority);
                break;  


                //case 6: Search a task
               



                //case 7 Exit
                cout << "Exiting Task Manager. \n";
                return 0;
                



                
            }
        }
    }

    return 0;
}