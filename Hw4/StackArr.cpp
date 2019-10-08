#include <iostream>
#include "HW4-Todo-StackArray.hpp"

using namespace std;

TodoStackArray::TodoStackArray(){
    
    stackTop = -1;
    
}

bool TodoStackArray::isEmpty(){
    
    if(stackTop == -1){
        return true;
    }
    return false;
    
}

bool TodoStackArray::isFull(){
    
    if(stackTop == MAX_STACK_SIZE - 1){
        
        return true;
    }
    else{
        return false;
    }
}

void TodoStackArray::push(string todoItem){
    
    if(stackTop == MAX_STACK_SIZE - 1) { // overflow case. 
			cout << "Stack full, cannot add new todo item." << endl;
			return;
		}
		
		TodoItem* newItem = new TodoItem;
		
		newItem -> todo = todoItem;
		
		stack[stackTop + 1] = newItem;
        
        stackTop ++;
        
        return;
    
}

void TodoStackArray::pop(){
    
    if(stackTop == -1) { // If stack is empty, pop should throw error. 
			cout << "Stack empty, cannot pop an item." << endl;
			return;
		}
		
		stackTop--;
        return;
}

TodoItem* TodoStackArray::peek(){
    
    if(stackTop == -1){
        cout << "Stack empty, cannot peek." << endl;
        return stack[0];
    }
    return stack[stackTop];
}