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
    // TODO: Implement removeTask
}

void TaskList::markTaskComplete(string description) {
    // TODO: Implement markTaskComplete
}

void TaskList::displayAllTasks() {
    // TODO: Implement displayAllTasks
}

void TaskList::displayByPriority(string priority) {
    // TODO: Implement displayByPriority
}

Task* TaskList::searchTask(string description)  {
    // TODO: Implement searchTask
}

int TaskList::getTaskCount() {
     // TODO: Implement getTaskCount

}