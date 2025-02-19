#include "taskList.h"
#include <iostream>
using namespace std;

// Setup a new TaskList
TaskList::TaskList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

TaskList::~TaskList() {
    
    Task* current = head;  //Implement destructor
    while (current != nullptr)
    {
        Task* temp = current; 
        current = current->getNext();
        delete temp; 
    }
}


void TaskList::addTask(string description, string priority, string dueDate) {
    //Implement addTask
    Task* newTask = new Task(description, priority, dueDate);

    if (!head) 
    {
        head = tail = newTask;
    } else if (priority == "High") {
        newTask->setNext(head);
        head = newTask;
    } else {
        Task* current = head;
        Task* previous = nullptr;

        while (current && (current->getPriority() == "High" || (current->getPriority() == "Medium" && priority == "Low"))) 
        {
            previous = current;
            current = current->getNext();
        }

        if (!previous) 
        {
            newTask->setNext(head);
            head = newTask;
        } else {
            newTask->setNext(current);
            previous->setNext(newTask);
        }

        if (!current)
         {
            tail = newTask;
        }
    }
    count++;
}

void TaskList::removeTask(string description) {
    //Implement removeTask
    if (!head)
     {
        cout << "Task list is empty. Nothing to remove.\n";
        return;
    }

    Task* current = head;
    Task* previous = nullptr;

    while (current) {
        if (current->getDescription() == description)
         {
            if (!previous) 
            {
                head = current->getNext();
            } else {
                previous->setNext(current->getNext());
            }

            if (current == tail)
             {
                tail = previous;
            }

            delete current;
            count--;
            cout << "Task \"" << description << "\" removed successfully.\n";
            return;
        }

        previous = current;
        current = current->getNext();
    }

    cout << "Task \"" << description << "\" not found.\n";
}

void TaskList::markTaskComplete(string description) {
    Task* current = head;

    while (current) {
        if (current->getDescription() == description) {
            current->setIsComplete(true);
            cout << "Task \"" << description << "\" marked as complete.\n";
            return;
        }
        current = current->getNext();
    }

    cout << "Task \"" << description << "\" not found.\n";
}

void TaskList::displayAllTasks() {
    if (!head) {
        cout << "Task list is empty.\n";
        return;
    }

    Task* current = head;
    cout << "\n=== Task List ===\n";

    while (current) {
        cout << "Description: " << current->getDescription() << "\n"
             << "Priority: " << current->getPriority() << "\n"
             << "Due Date: " << current->getDueDate() << "\n"
             << "Completion Status: " << (current->getIsComplete() ? "Complete" : "Incomplete") << "\n\n";
        current = current->getNext();
    }
}

void TaskList::displayByPriority(string priority) {
   //fix 
}
Task* TaskList::searchTask(string description) {
    Task* current = head;

    while (current) {
        if (current->getDescription() == description) {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

int TaskList::getTaskCount() {
    return count;
}

