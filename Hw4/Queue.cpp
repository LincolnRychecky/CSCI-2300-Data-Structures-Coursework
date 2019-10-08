#include <iostream>
#include "HW4-Todo-QueueLinkedList.hpp"

using namespace std;

TodoQueueLinkedList::TodoQueueLinkedList(){
    
    queueFront = nullptr;
    queueEnd = nullptr;
    
}

TodoQueueLinkedList::~TodoQueueLinkedList(){
    
     while(!isEmpty()){
        dequeue();
    }
    queueFront = nullptr;
    queueEnd = nullptr;
    
}

bool TodoQueueLinkedList::isEmpty(){
    
     if(queueFront == nullptr){
        return true;
    }
    return false;
    
}

void TodoQueueLinkedList::enqueue(string todoItem){
    
    //basically inserting a node at the end
    //allocate a new node
    TodoItem * newItem = new TodoItem;
    //Assign the value
    newItem-> todo = todoItem;
    newItem-> next = nullptr;
    if(isEmpty()){
        queueFront = newItem;
    }
    else{
        queueEnd -> next =newItem;
    }
    queueEnd = newItem;
    
}

void TodoQueueLinkedList::dequeue(){
    
    //create a temp pointer 
    TodoItem * temp = new TodoItem; 
    //point to front
    if(isEmpty()){ //checking if queue is empty
        cout << "Queue empty, cannot dequeue an item." << endl;
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

TodoItem* TodoQueueLinkedList::peek(){
    
    if(isEmpty()){
        cout << "Queue empty, cannot peek." << endl;
        return queueFront;
    }
    
    return queueFront;
    
}