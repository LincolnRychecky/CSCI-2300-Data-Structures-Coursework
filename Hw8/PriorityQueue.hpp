#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <string>

// Structure to store the patients information: Name, Injury Severity and Treatment Time
struct PatientNode
{
    std::string name;
    int injurySeverity;
    int treatmentTime;
};

/* class PriorityQueue for storing the patients in a queue.
 * check the homework document on moodle for function descriptions
*/

class PriorityQueue
{
    public:
        PriorityQueue(int _queueSize); //done
        ~PriorityQueue(); //done
        void enqueue (std::string _name, int _injurySeverity, int _treatmentTime); //done
        std::string peekName(); //done
        int peekInjurySeverity(); //done
        int peekTreatmentTime(); //done
        void dequeue(); //done
        bool isFull(); //done
        bool isEmpty(); //done
        void print();
    private:
        /* member functions */
        void repairUpward(int nodeIndex); //done
        void repairDownward(int nodeIndex); //done

        /* Instance variables */
        PatientNode* priorityQueue; //points to the array used to implement priority queue
        int currentQueueSize;
        int maxQueueSize;
};
#endif
