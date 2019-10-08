// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"

using namespace std;

node* HashTable::createNode(string key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    //array of node*'s
    table = new node*[tableSize];
    
    for(int i = 0; i < tableSize; i++ ){
        table[i] = nullptr;
    }
}

//function to calculate hash function
unsigned int HashTable::hashFunction(string key)
{
    unsigned int hash = 0;
    for(int i = 0; i < tableSize; i++){
        //ASKI value
        hash += key[i];
    }
    hash = hash%tableSize;
    return hash ;
}

//function to search
node* HashTable::searchItem(string key)
{
    int hashValue = hashFunction(key);
    
    //create a pointer pointing at the index of the hash value which would be the head of the linked list at that index
    node* temp = table[hashValue];
    //check if key of pointer is the required key
    while(temp != nullptr){
        //if true return the node
        if(temp->key == key){
            return temp;
        }
        //else move to next pointer
        temp = temp -> next;
    }
    return nullptr;
}

//function to insert
bool HashTable::insertItem(string key)
{
    unsigned int hashValue = hashFunction(key);
    if(!searchItem(key)){
        //make a new node with the create node function
        node * newnode = createNode(key, nullptr);
        
        if(table[hashValue] == nullptr){
            table[hashValue] = newnode;
        }
        else{
            newnode -> next = table[hashValue];
            table[hashValue] = newnode;
            return true;
        }
    }
    else{
        cout << "Duplicate Entry" << endl;
    }
    return false;
}

// function to delete
bool HashTable::deleteItem(string key)
{
    unsigned int hashValue= hashFunction(key);
    node * temp = table[hashValue];
    bool flag = false;
    if(temp == nullptr){
        cout << "'Key not present in the table'" << endl;
        return flag;
    }
    //if the first element is what we want to delete, set the head to the next element;
    if(temp -> key == key){
        table[hashValue] = temp -> next;
        delete temp;
        flag = true;
        return flag;
    }
    else{
        while(temp && !flag){
            if(temp -> next -> key == key){
                flag = true;
            }
            else{
                temp = temp -> next;
            }
        }
        if(flag == true){
            node * del = temp -> next;
            temp->next = temp->next->next;
            delete del;
            del = nullptr;
        }
    }
    return flag;
}

// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* temp = table[i];
        while(temp)
        {
            cout<< temp->key;
            if(temp->next!=nullptr)
            {
                cout<<"-->";
            }
            temp = temp->next;
        }
        cout<<endl;

    }
}
