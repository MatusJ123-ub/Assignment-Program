#include <string>
using namespace std;

class Task {
    public:
        Task(string desc, string prio, string date);

        string getDescription();
        string getPriority();
        string getDueDate();
        bool getIsComplete();
        Task* getNext();
        
        void setDescription(string desc);
        void setPriority(string prio);
        void setDueDate(string date);
        void setIsComplete(bool complete);
        void setNext(Task* nextTask);

     private:
        string description;
        string priority;       /* "High", "Medium", "Low" */
        string dueDate;   
        bool isComplete;
        Task* next;
};