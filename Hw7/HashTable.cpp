#include<iostream>
#include <fstream>
#include "HashTable.hpp"
#include <string>
using namespace std;

wordItem* searchItem(string key, wordItem** table, int hashTableSize)
{
    unsigned int hashValue = 5381;
    
    for(unsigned int i = 0; i < key.length(); i++){
        hashValue = hashValue*33 + key[i];
    }
    hashValue = hashValue % hashTableSize;
    
    //create a pointer pointing at the index of the hash value which would be the head of the linked list at that index
    wordItem* temp = table[hashValue];
    //check if key of pointer is the required key
    while(temp != nullptr){
        //if true return the node
        if(temp->word == key){
            return temp;
        }
        //else move to next pointer
        temp = temp -> next;
    }
    return nullptr;
}

void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable) //done
{
    ifstream writeFile; //create ofstream variable
    writeFile.open(ignoreWordFileName); //open file in Outputmode
    
    string line1;
    
    while(getline(writeFile,line1)){
        stopWordsTable.addWord(line1);
    }
    writeFile.close();
}

bool isStopWord(string word, HashTable &stopWordsTable){
    
    return stopWordsTable.isInTable(word);
    
}

unsigned int HashTable:: getHash(string word){
    
    unsigned int hash = 5381;
    for(unsigned int i = 0; i < word.length(); i++){
        hash = hash*33 + word[i];
    }

    hash = hash % hashTableSize;
    
    return hash;
}

HashTable::HashTable(int _hashTableSize)
{
    //array of node*'s
    hashTableSize = _hashTableSize;
    hashTable = new wordItem*[hashTableSize];
    numItems = 0;
    numCollisions = 0;
    for(int i = 0; i < hashTableSize; i++ ){
        hashTable[i] = nullptr;
    }
}



wordItem* HashTable::searchTable(string word){
    
    return searchItem(word,hashTable,hashTableSize);
    
}

void HashTable:: addWord(string word){
    unsigned int hashValue = getHash(word);
    if(!searchTable(word)){
        //make a new node with the create node function
        wordItem* newnode = new wordItem;
        newnode->word = word;
        newnode->count = 1;
        newnode->next = nullptr;
        
        if(hashTable[hashValue] == nullptr){
            hashTable[hashValue] = newnode;
        }
        else{
            newnode -> next = hashTable[hashValue];
            hashTable[hashValue] = newnode;
            numCollisions++;
        }
        numItems++;
    }
}

int HashTable::getTotalNumWords()
{
    int counter = 0;
    for(int i = 0; i < hashTableSize; i++){
        wordItem* temp = hashTable[i];
        while(temp != nullptr){
            counter += temp -> count;
            temp = temp -> next;
        }
    }
    return counter;
}

void arraySort(wordItem** list, int length) //done
{
    int sorted = 0;
    int indexBig;
    int maxBig = 0;
    bool change = false;
    wordItem* holder;
    for(int i = 0; i < length; i++){
        maxBig = list[sorted] -> count;
        for(int z = sorted+1; z < length; z++){
            
            if(list[z] -> count > maxBig){
                maxBig = list[z] -> count;
                indexBig = z;
                change = true;
            }
        }
        if(change == true){
            holder = list[sorted];
            list[sorted] = list[indexBig];
            list[indexBig] = holder;
            change = false;
        }
        sorted ++;
    }
}

void HashTable:: printTopN(int n){
    
    wordItem** tempArr = new wordItem*[n];
    wordItem* itemHold;
    int inTempArr = 0;
    //to navigate throguh each index in hash table
    for(int i = 0; i < hashTableSize; i++){
        itemHold = hashTable[i];
        //if the temnp array isnt full yet, just add at next empty index
        if(inTempArr < n && itemHold != nullptr){
            tempArr[inTempArr] = itemHold;
            inTempArr++;
        }
        else if(itemHold != nullptr){
            arraySort(tempArr, n);
            //go through sorted temp array, and as soon as you find an index with a count less than what you have in temp, make the index that temp pointer
            int minCount = 10000000;
            int minIndex = 0;
            for(int x = 0; x < n; x++){
                if(tempArr[x] -> count < minCount){
                    minCount = tempArr[x] -> count;
                    minIndex = x;
                }
            }
            
            if(itemHold -> count > minCount){
                tempArr[minIndex] = itemHold;
            }
            
        }
        
        if(itemHold != nullptr){
         itemHold = itemHold -> next;
        }
        
        while(itemHold != nullptr){
            
        if(inTempArr < n && itemHold != nullptr){
            tempArr[inTempArr] = itemHold;
            inTempArr++;
        }
        else if(itemHold != nullptr){
                    arraySort(tempArr, n);
                //go through sorted temp array, and as soon as you find an index with a count less than what you have in temp, make the index that temp pointer
                int minCount = 10000000;
                int minIndex = 0;
                for(int y = 0; y < n; y++){
                    if(tempArr[y] -> count < minCount){
                        minCount = tempArr[y] -> count;
                        minIndex = y;
                    }
                }
                
                if(itemHold -> count > minCount){
                    tempArr[minIndex] = itemHold;
                }
            }        
                
            itemHold = itemHold -> next;
        }
        
    }
    
    for(int i = 0; i < n; i++){
        cout << tempArr[i]-> count << " - " << tempArr[i]-> word << endl;
    }
    
   
}

void HashTable:: incrementCount(string word){
    
    wordItem* temp = searchTable(word);
    
    if(temp != nullptr){
        temp -> count = temp -> count + 1;
    }
}

int HashTable:: getNumCollisions(){
    return numCollisions;
}

int HashTable:: getNumItems(){
    return numItems;
}

HashTable:: ~HashTable(){
    
    for (int i = 0; i < hashTableSize; i++)
	    {
                wordItem* entry = hashTable[i];
                while (entry != nullptr)
	        {
                    wordItem* prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] hashTable;
}

bool HashTable:: isInTable(string word){
    
    wordItem* temp = searchTable(word);
    
    if(temp != nullptr){
        return true;
    }
    
        return false;
    
}