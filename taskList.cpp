#include "taskList.h"
#include <iostream>
using namespace std;

// Setup a new TaskList (constructor)
TaskList::TaskList()
 {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Cleans up dynamically allocate memory (Desctructor)
TaskList::~TaskList() 
{

    Task* current = head;
    while (current != nullptr)
    {
        Task* temp = current; 
        current = current->getNext();
        delete temp; 
    }
}

//Adds a task to the task list 
void TaskList::addTask(string description, string priority, string dueDate) 
{
    // @todo Run checks to see that the description, priority and due-date are in the correct format
    // Can use regex for this again
    Task* newTask = new Task(description, priority, dueDate); //Creates a new task

    if (!head) 
    {
        head = tail = newTask;
    } else if (priority == "High") {    
        newTask->setNext(head);
        head = newTask;
    } else {  
        Task* current = head;
        Task* previous = nullptr;

        while (current && (current->getPriority() == "High" || (current->getPriority() == "Medium" && priority == "Low"))) //finds correct position based on priority.
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
//Removes a task based on its description/name. 
void TaskList::removeTask(string description)
 {

    if (!head)
     {
        cout << "Task list is empty. Nothing to remove.\n";
        return;
    }

    Task* current = head;
    Task* previous = nullptr;

    while (current) { //Traverses the list
        if (current->getDescription() == description) //if task is found
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

            delete current;  //deletes task
            count--;
            cout << "Task \"" << description << "\" removed successfully.\n";
            return;
        }

        previous = current;
        current = current->getNext();
    }

    cout << "Task \"" << description << "\" not found.\n";
}

//Marks a task as complete based on its description. 
void TaskList::markTaskComplete(string description)
 {
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

//Displays all tasks  placed by user. 
void TaskList::displayAllTasks() 
{
    if (!head) {
        cout << "Task list is empty.\n";
        return;
    }

    Task* current = head;
    cout << "\n=== Task List ===\n";

    while (current) { //Traverses List 
        cout << "Description: " << current->getDescription() << "\n"
             << "Priority: " << current->getPriority() << "\n"
             << "Due Date: " << current->getDueDate() << "\n"
             << "Completion Status: " << (current->getIsComplete() ? "Complete" : "Incomplete") << "\n\n";
        current = current->getNext();
    }
}

//Displays taks by priority. 
void TaskList::displayByPriority(string priority) 
{
   if (!head)
   {
    cout << "Task list is empty.\n";
    return;
   }

   Task* current = head;
   bool found = false; 

   cout << "\n Tasks with Priorrity: " << priority << "\n";
   while (current) {
    if(current->getPriority() == priority) 
    {
        cout << "Description: " << current->getDescription() << "\n"
                 << "Due Date: " << current->getDueDate() << "\n"
                 << "Completion Status: " << (current->getIsComplete() ? "Complete" : "Incomplete") << "\n\n";
            found = true;
        }
        current = current->getNext();
    }

    if (!found) {
        cout << "No tasks found with priority: " << priority << ".\n";
    } 
    }
   


//Searches for a task based on description/name and returns a pointer. 
Task* TaskList::searchTask(string description)
{
    Task* current = head;

    while (current) {
        // @todo Use regex to search both the title and description of the task
        if (current->getDescription() == description) {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

//returns the total number of tasks in the list. 
int TaskList::getTaskCount() 
{
    return count;
}

