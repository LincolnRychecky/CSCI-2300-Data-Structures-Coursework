#include<iostream>
#include <fstream>
#include "HashTable.hpp"
using namespace std;


int main(int argc, char *argv[]){
    
    //cout << argv[0];
    
    HashTable table(50);
    HashTable table1(stoi(argv[4]));
    getStopWords(argv[3], table);
    
    ifstream writeFile; //create ofstream variable
    writeFile.open(argv[2]); //open file in Outputmode //arguement here //argv[2] //"HW2-HungerGames_edit.txt"
  
    string name;
    
    int uniqueNonStopWords = 0;
    
    int totalNonStopWords = 0;
    
    while(writeFile >> name){ //while there are still words being read in, continue
                
                if(isStopWord(name,table)){
                    //do nothing, it is a stop word 
                }else{
                        
                    if(table1.isInTable(name) == false){
                        table1.addWord(name);
                        uniqueNonStopWords++;
                        totalNonStopWords++;
                    }    
                    else{
                        
                        table1.incrementCount(name);
                        totalNonStopWords++;
                    }    
            }
    }
    
    table1.printTopN(stoi(argv[1])); //arguement here //stoi(argv[1]) //10
    cout << "#" << endl;
    cout << "Number of collisions: " << table1.getNumCollisions()  << endl;
    cout << "#" << endl;
    cout << "Unique non-stop words: " << uniqueNonStopWords << endl;
    cout << "#" << endl;
    cout << "Total non-stop words: " << totalNonStopWords << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}