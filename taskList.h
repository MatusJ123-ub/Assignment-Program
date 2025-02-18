#include "task.h"
#include <string>
using namespace std;

class TaskList {
    private:
        Task* head;
        Task* tail;
        int count;

    public:
        TaskList();
        ~TaskList();
        
        void addTask(string description, string priority, string dueDate);
        void removeTask(string description);
        void markTaskComplete(string description);
        void displayAllTasks();
        void displayByPriority(string priority);
        Task* searchTask(string description);
        int getTaskCount();
    };