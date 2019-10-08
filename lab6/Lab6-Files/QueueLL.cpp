#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
    
}

QueueLL::~QueueLL()
{
    while(!isEmpty()){
        dequeue();
    }
    queueFront = nullptr;
    queueEnd = nullptr;
}

bool QueueLL::isEmpty()
{
    if(queueFront == nullptr){
        return true;
    }
    return false;
}

void QueueLL::enqueue(int newkey)
{
    //basically inserting a node at the end
    //allocate a new node
    Node * newnode = new Node;
    //Assign the value
    newnode-> key = newkey;
    newnode-> next = nullptr;
    if(isEmpty()){
        queueFront = newnode;
    }
    else{
        queueEnd -> next =newnode;
    }
    queueEnd = newnode;

}

void QueueLL::dequeue()
{
    //create a temp pointer 
    Node * temp = new Node; 
    //point to front
    if(isEmpty()){ //checking if queue is empty
        cout << "queue is empty. Can't dequeue." << endl;
        return;
    }
    else{
        temp = queueFront;
        if(queueEnd == queueFront){ //checking if queue contains only 1 element 
            queueFront = nullptr;
            queueEnd = nullptr;
        } 
        else{
            //move the front to the next node
            queueFront = queueFront -> next;
        }
        delete temp;
    }
    
    return;
}

int QueueLL::peek()
{
    if(isEmpty()){
        cout << "queue is empty. can't peek" << endl;
        return -1;
    }
    
    return queueFront -> key;
}

