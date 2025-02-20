#include "task.h"

// Setup a new Task
Task::Task(string desc, string prio, string date) 
{
    description = desc;
    priority = prio;
    dueDate = date;
    isComplete = false;
    next = nullptr;
}

string Task::getDescription()
 {
    return description; //Return the description of this task
}

string Task::getPriority() 
{
    return priority; //Return the priority of this task
}

string Task::getDueDate() 
{
    return dueDate; //Return the due date of this task
}

bool Task::getIsComplete() 
{
    return isComplete; //Return whether the task is complete or not
}

Task* Task::getNext() 
{
    return next; //Return pointer to the next task in the list
}

void Task::setDescription(string desc)
 {
    description = desc; //Set the description of this task to the provided value
}

void Task::setPriority(string prio) 
{
    priority = prio; //Set the priority of this task to the provided value
}

void Task::setDueDate(string date) 
{
    dueDate = date; //Set the due date of this task to the provided value
}

void Task::setIsComplete(bool complete) 
{
    isComplete = complete; //Set the completion status of this task to the provided value
}

void Task::setNext(Task* nextTask) 
{
    next = nextTask; //Set the next pointer to the provided task
}