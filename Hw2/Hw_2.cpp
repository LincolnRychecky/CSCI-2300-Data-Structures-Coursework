// ==========================================
// Created: September 19, 2018
// Lincoln Rychecky
//
// Description: Counts unique words in a file
// outputs the top N most common words
// ==========================================
 
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
 
using namespace std;
 
// struct to store word + count combinations
struct wordItem
{
    string word;
    int count;
};
 
/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore/stop words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/
void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords); //done
 
/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param _vecIgnoreWords - the vector type of string storing ignore/stop words
* @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, vector<string> &_vecIgnoreWords); //done
 
/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array (including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length); //done
 
/*
* Function name: arraySort
* Purpose: sort an array of wordItems, decreasing, by their count fields
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/
void arraySort(wordItem list[], int length);
 
/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of wordItems
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN);
 
const int STOPWORD_LIST_SIZE = 50;
 
const int INITIAL_ARRAY_SIZE = 100;
 
// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt

//void doubleArray(wordItem initalArr[], int doubleCoefficient, wordItem* arrPoint[]){
    
//}

void addNonStop(wordItem arr1[], int capacity);



int main(int argc, char *argv[])
{
    /*
    vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
 
    // verify we have the correct # of parameters, else throw error msg & return
    if (argc != 4)
    {
        cout << "Usage: ";
        cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
        cout << endl;
        return 0;
    }
*/

    /* **********************************
    1. Implement your code here.
    
    Read words from the file passed in on the command line, store and
    count the words.
    
    2. Implement the six functions after the main() function separately.
    ********************************** */
    
    vector <string> ignoreWord[STOPWORD_LIST_SIZE]; 
    getStopWords(argv[3], ignoreWord); //problem with wrong parameter type
    
    
    ifstream writeFile; //create ofstream variable
    writeFile.open(argv[2]); //open file in Outputmode
  
    wordItem* arrPoint = new wordItem[INITIAL_ARRAY_SIZE];
    int capacity = 0;
  
    string line1;
    
    stringstream ss();
    
    bool found = false;
    
    int foundIndex;
    
    while(getline(writeFile,line1) ){
            string name;    
            while(line1 >> name){ //problem with it saying that getline cant work here
                cout << "testing: " << name << endl;
                if(isStopWord(name,ignoreWord)){
                    
                }else{
                
                for(int i = 0; i < capacity; i++){
                    
                    if(arrPoint[i].word == name){
                        found = true;
                        foundIndex = i;
                        break;
                    }
                }
                
                if(found == false){
                    arrPoint[capacity].word = name;
                    arrPoint[capacity].count = 1;
                    capacity++;
                }else{
                    arrPoint[foundIndex].count += 1;
                    found = false;
                }
            }
        }
        //getline(ss,name);//problem with it saying that getline cant work here
        
        if(isStopWord(name,ignoreWord)){
                
            }else{
         for(int i = 0; i < capacity; i++){
                
                if(arrPoint[i].word == name){
                    found = true;
                    foundIndex = i;
                    break;
                }
            }
            
            if(found == false){
                arrPoint[capacity].word = name;
                arrPoint[capacity].count = 1;
                capacity++;
            }else{
                arrPoint[foundIndex].count += 1;
                found = false;
            }
        
            }
        
    }
    
    
    
    
    
    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
    return 0;
}








 
void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords) //done
{
    ifstream writeFile; //create ofstream variable
    writeFile.open(ignoreWordFileName); //open file in Outputmode
  
    string line1;
    
    while(getline(writeFile,line1)){
        
        _vecIgnoreWords.push_back(line1);
        
    }
    writeFile.close();
}
 
bool isStopWord(string word, vector<string> &_vecIgnoreWords) //done
{
    for(int i = 0; i < _vecIgnoreWords.size(); i++){
        
        if(word == _vecIgnoreWords[i]){
            return true;
        }
        
    }
    
    return false;
}
 
int getTotalNumberNonStopWords(wordItem list[], int length) //done
{
    int runningTotal = 0;
    
    for(int i = 0; i < length; i++){
        
        runningTotal += list[i].count;

    }
    
    return runningTotal;
}
 
void arraySort(wordItem list[], int length) //done
{
    int sorted = 0;
    int indexBig;
    int maxBig = 0;
    bool change = false;
    wordItem holder;
    for(int i = 0; i < length; i++){
        maxBig = list[sorted].count;
        for(int z = sorted+1; z < length; z++){
            
            if(list[z].count > maxBig){
                maxBig = list[z].count;
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
 
void printTopN(wordItem wordItemList[], int topN)//done
{
    int counter = 0;
    while(counter < topN){
         cout << wordItemList[counter].count << " - " << wordItemList[counter].word << endl;
         counter++;
    }
}

void addNonStop(wordItem arr1[], int capacity, string word1){
    
    int foundIndex;
    bool found = false;
    
    for(int i = 0; i < capacity; i++){
                    
                    if(arr1[i].word == word1){
                        found = true;
                        foundIndex = i;
                        break;
                    }
                }
                
                if(found == false){
                    arr1[capacity].word = word1;
                    arr1[capacity].count = 1;
                    capacity++;
                }else{
                    arr1[foundIndex].count += 1;
                    found = false;
                }
    
}