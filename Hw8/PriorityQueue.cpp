#include<iostream>
#include<climits>
#include "PriorityQueue.hpp"
using namespace std;

void swap(PatientNode *x, PatientNode *y)
{
    PatientNode temp = *x;
    *x = *y;
    *y = temp;
}

void PriorityQueue::print(){
    cout << currentQueueSize << endl;
    for(int i = 1; i <= currentQueueSize; i++){
        cout << priorityQueue[i].name << " " << priorityQueue[i].injurySeverity << " " << priorityQueue[i].treatmentTime << endl;
    }
}


PriorityQueue::PriorityQueue(int _queueSize)
{
    maxQueueSize = _queueSize;
    currentQueueSize = 0;
    priorityQueue = new PatientNode[maxQueueSize + 1]; //+1 because you keep the 0th index empty

}

void PriorityQueue::enqueue(string _name, int _injurySeverity, int _treatmentTime){
    
// Corner case: If heap is full
    if(currentQueueSize == maxQueueSize){
        cout << "Heap is full. Cannot push the key." << endl;
        return;
    }
    // increment the heap size
    currentQueueSize ++;
    // insert the new key at the end
    PatientNode temp;
    temp.name = _name;
    temp.injurySeverity = _injurySeverity;
    temp.treatmentTime = _treatmentTime;
    priorityQueue[currentQueueSize] = temp;
    // Fix the min heap property if it is violated
    
    repairUpward(currentQueueSize);
    
}

void PriorityQueue::repairDownward(int nodeIndex)
{
    
    nodeIndex += 1;
    
    for(int i = 1; i < currentQueueSize; i++)
    {
        for(int j = 1; j < currentQueueSize; j++)
        {
            if(priorityQueue[j].injurySeverity < priorityQueue[j+1].injurySeverity)   //just replace > by < for descending order. 
            {
                swap(priorityQueue[j],priorityQueue[j+1]);
            }
            else if(priorityQueue[j].injurySeverity == priorityQueue[j+1].injurySeverity){
                if(priorityQueue[j].treatmentTime > priorityQueue[j+1].treatmentTime){
                    swap(priorityQueue[j],priorityQueue[j+1]);
                }
            }
        }
    }
    
    // if(nodeIndex > currentQueueSize){
    //     cout << "given index cannot be greater than head size" << endl;
    //     return;
    // }
    // // left and right children
    // int l = nodeIndex*2;
    // int r = nodeIndex*2 + 1;

    // // set given index as smallest
    // int biggest = nodeIndex;

    // // compare it with its left and right children and set smallest
    
    // if(l < currentQueueSize && priorityQueue[biggest].injurySeverity < priorityQueue[l].injurySeverity){
    //     biggest = l;
    // }
    // else if(l < currentQueueSize && priorityQueue[biggest].injurySeverity == priorityQueue[l].injurySeverity){
    //     if(priorityQueue[biggest].treatmentTime > priorityQueue[l].treatmentTime){
    //         biggest = l;
    //     }
    // }
    // if(r < currentQueueSize && priorityQueue[biggest].injurySeverity < priorityQueue[r].injurySeverity){
    //     biggest = r;
    // }
    // else if(r < currentQueueSize && priorityQueue[biggest].injurySeverity == priorityQueue[r].injurySeverity){
    //     if(priorityQueue[biggest].treatmentTime > priorityQueue[r].treatmentTime){
    //         biggest = r;
    //     }
    // }
    // // swap if not less than its one of the children
    // if(biggest != nodeIndex){
    //         swap(&priorityQueue[biggest], &priorityQueue[nodeIndex]);
    //         repairDownward(biggest);
    //     }
}


void PriorityQueue::repairUpward(int nodeIndex)
{
    
    for(int i = 1; i < nodeIndex; i++)
    {
        for(int j = 1; j < nodeIndex; j++)
        {
            if(priorityQueue[j].injurySeverity < priorityQueue[j+1].injurySeverity)   //just replace > by < for descending order. 
            {
                swap(priorityQueue[j],priorityQueue[j+1]);
            }
            else if(priorityQueue[j].injurySeverity == priorityQueue[j+1].injurySeverity){
                if(priorityQueue[j].treatmentTime > priorityQueue[j+1].treatmentTime){
                    swap(priorityQueue[j],priorityQueue[j+1]);
                }
            }
        }
    }
    
    
    
    
    
    
    // if( nodeIndex > currentQueueSize){
    //     cout << "index cannot be greater than head size" << endl;
    //     return;
    // }
    // int p = nodeIndex / 2;
    
    // if(p != 0 && priorityQueue[p].injurySeverity < priorityQueue[nodeIndex].injurySeverity){
    //     swap(&priorityQueue[p], &priorityQueue[nodeIndex]);
    //   repairUpward(p);
    // }
    // else if(p != 0 && priorityQueue[p].injurySeverity == priorityQueue[nodeIndex].injurySeverity){
    //     if(priorityQueue[p].treatmentTime > priorityQueue[nodeIndex].treatmentTime){
    //         swap(&priorityQueue[p], &priorityQueue[nodeIndex]);
    //         repairUpward(p); //edit
    //     }
    // }
    
}

bool PriorityQueue::isEmpty(){
    
    if(currentQueueSize == 0){
        return true;
    }
    return false;
}

bool PriorityQueue::isFull(){
    
    if(currentQueueSize == maxQueueSize){
        return true;
    }
    return false;
}

int PriorityQueue::peekTreatmentTime(){
    
    return priorityQueue[1].treatmentTime;
    
}

int PriorityQueue::peekInjurySeverity(){
    
    return priorityQueue[1].injurySeverity;
    
}

string PriorityQueue::peekName(){
    
    return priorityQueue[1].name;
    
}

PriorityQueue::~PriorityQueue(){
    
    delete[] priorityQueue;
    
}

void PriorityQueue::dequeue(){
    
    //CORNER CASE: HEAP EMPTY, HEAP SIZE 1
    if(currentQueueSize == 0){
        return;
    }
    if(currentQueueSize == 1){
        currentQueueSize --;
        return;
    }
    priorityQueue[1] = priorityQueue[currentQueueSize];
    
    currentQueueSize --;
    
    for(int i = 0; i < maxQueueSize; i++){
        repairDownward(1);
    }
    
}