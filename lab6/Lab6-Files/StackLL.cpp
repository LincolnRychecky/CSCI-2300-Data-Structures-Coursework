#include <iostream>
#include "StackLL.hpp"

using namespace std;

StackLL::StackLL()
{
  
  stackHead = nullptr;
  
}

StackLL::~StackLL()
{
  
  while(stackHead != nullptr){
    pop();
  }
  
  stackHead = nullptr;
}

bool StackLL::isEmpty()
{
  if(stackHead != nullptr){
    return false;
  }
    return true;
}

void StackLL::push(int newKey)
{
  //allocate new node
  Node * newNode = new Node;
  //assign value
  newNode -> key = newKey;
  //if stack has nothing in it, set newnode to head
  if(isEmpty()){
    
    stackHead =newNode;
    stackHead -> next = nullptr;
    return;
  }
  newNode -> next = stackHead;
  stackHead = newNode;
  return;
  
}

//deleting from the begining 
void StackLL::pop()
{
  //create a temp node
  Node* temp = new Node;
  //assign head to temp
  if(isEmpty()){
    cout << "Stack is empty. Can't pop anything" << endl;
    return;
  }
  temp = stackHead;
  //movehead
  stackHead = stackHead -> next;
  //delte temp
  delete temp;
  return;
}

int StackLL::peek()
{
  //returning value at head
  if(isEmpty()){
    cout << "stack is empty" << endl;
    return -1;
  }
  return stackHead -> key;
}
