#include "task.h"

// Setup a new Task
Task::Task(string desc, string prio, string date) {
    description = desc;
    priority = prio;
    dueDate = date;
    isComplete = false;
    next = nullptr;
}

string Task::getDescription() {
    // TODO: Return the description of this task
}

string Task::getPriority() {
    // TODO: Return the priority of this task
}

string Task::getDueDate() {
    // TODO: Return the due date of this task
}

bool Task::getIsComplete() {
    // TODO: Return whether the task is complete or not
}

Task* Task::getNext() {
    // TODO: Return pointer to the next task in the list
}

void Task::setDescription(string desc) {
    // TODO: Set the description of this task to the provided value
}

void Task::setPriority(string prio) {
    // TODO: Set the priority of this task to the provided value
}

void Task::setDueDate(string date) {
    // TODO: Set the due date of this task to the provided value
}

void Task::setIsComplete(bool complete) {
    // TODO: Set the completion status of this task to the provided value
}

void Task::setNext(Task* nextTask) {
    // TODO: Set the next pointer to the provided task
}