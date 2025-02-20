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
            case 1: //Adds new task
                cout << "Enter task description: ";
                getline(cin, description);     //Gets task description from user input 
                cout << "Enter priority (High/Medium/Low): ";
                getline(cin, priority);        //GEt priority level from user input 
                cout << "Enter due date (YYYY-MM-DD): ";
                getline(cin, dueDate);         //Gets due date from user input 
                taskList.addTask(description, priority, dueDate);  //adds task to the list
                cout << "Task added successfully!\n";
                break;

            case 2: // Removes task
                cout << "Enter the description of the task to remove: ";
                getline(cin, description);     //gets task description from user input 
                taskList.removeTask(description);  //calls function to remove task from the list. 
                break;

            case 3: // Mark task as complete 
                cout << "Enter the description of the task to mark as complete: ";
                getline(cin, description);    //gets description of task
                taskList.markTaskComplete(description);  //calls function to mark task as complete. 
                break;

            case 4: //Display all tasks 
                taskList.displayAllTasks();     //Calls function to displaty all tasks inputted by user. 
                break;

            case 5: //Display tasks by priority 
                cout << "Enter priority to filter by (High/Medium/Low): ";
                getline(cin, priority);       //Input priority to filter tasks.
                taskList.displayByPriority(priority);  //calls functions to display tasks by priority
                break;

            case 6:// Search for task 
                cout << "Enter the description of the task to search: ";
                getline(cin, description); //get task description from user input
                {
                    Task* task = taskList.searchTask(description); //if task is found it displays the details.
                    if (task) {
                        cout << "\n=== Task Found ===\n"
                             << "Description: " << task->getDescription() << "\n"
                             << "Priority: " << task->getPriority() << "\n"
                             << "Due Date: " << task->getDueDate() << "\n"
                             << "Completion Status: " << (task->getIsComplete() ? "Complete" : "Incomplete") << "\n"; 
                    }else {
                        cout << "Error: task not fouund.\n";  //if task is not found, it notifes the user. 
                    }
                }
                    break; 

        case 7: //Exists
        cout << "Exiting Task Manager.\n";
        return 0;

         default: //Any other number apart from 1-7
        cout << "Invalid choice. Please try again.\n";
        break;
    }
}

return 0;
}