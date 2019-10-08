#include <iostream>
#include "HW4-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray(){
    
    queueFront = -1;
    queueEnd = -1;
    
}

bool TodoQueueArray::isEmpty(){
    
    if(queueFront == -1 && queueEnd == -1){
        return true;
    }
    return false;
    
}
    
bool TodoQueueArray::isFull(){
    
    if (queueFront == 0 && queueEnd == 4){
        return true;
    }
    if (queueFront - 1 == queueEnd){
        return true;
    }
    return false;
}
    
void TodoQueueArray::enqueue(string todoItem){
    
    if(isFull())
		{
			cout<<"Queue full, cannot add new todo item." << endl;
			return;
		}
		if (isEmpty())
		{ 
			queueFront = 0;
			queueEnd = 0;
		}
		else
		{
		    queueEnd = (queueEnd + 1) % MAX_QUEUE_SIZE;
		}
		
		TodoItem* newItem = new TodoItem;
		newItem -> todo = todoItem;
		
	    queue[queueEnd] = newItem;
    
}

void TodoQueueArray::dequeue(){
    
		if(isEmpty())
		{
			cout<<"Queue empty, cannot dequeue an item." << endl;
			return;
		}
		
		if(queueFront == queueEnd ) 
		{
			queueEnd = -1;
			queueFront = -1;
		}
		
		else
		{
			queueFront = (queueFront + 1) % MAX_QUEUE_SIZE;
		}
		
		return;
}

TodoItem* TodoQueueArray::peek(){
    
    if(isEmpty()){
        cout << "Queue empty, cannot peek." << endl;
        return queue[0];
    }
    
    return queue[queueFront];
    
}