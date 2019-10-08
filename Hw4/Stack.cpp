#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList::TodoStackLinkedList(){
    stackHead = nullptr;
}

TodoStackLinkedList::~TodoStackLinkedList(){
    
    while(stackHead != nullptr){
    pop();
  }
  
  stackHead = nullptr;
    
}

bool TodoStackLinkedList::isEmpty(){
    
    if(stackHead != nullptr){
    return false;
  }
    return true;
    
}

void TodoStackLinkedList::push(string todoItem){
    
    //allocate new node
  TodoItem * newItem = new TodoItem;
  //assign value
  newItem -> todo = todoItem;
  //if stack has nothing in it, set newnode to head
  if(isEmpty()){
    
    stackHead =newItem;
    stackHead -> next = nullptr;
    return;
  }
  newItem -> next = stackHead;
  stackHead = newItem;
  return;
}

void TodoStackLinkedList::pop(){
    
    //create a temp node
  TodoItem* temp = new TodoItem;
  //assign head to temp
  if(isEmpty()){
    cout << "Stack empty, cannot pop an item." << endl;
    return;
  }
  temp = stackHead;
  //movehead
  stackHead = stackHead -> next;
  //delte temp
  delete temp;
  return;
}

TodoItem* TodoStackLinkedList::peek(){
    
    //returning value at head
  if(isEmpty()){
    cout << "Stack empty, cannot peek." << endl;
    return stackHead;
  }
  return stackHead;
    
}