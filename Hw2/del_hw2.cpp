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

bool addNonStop(wordItem arr1[], int capacity, string word1);

void doubleArray(wordItem* arr1, int mult);

//int argc, char *argv[]
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
    
    vector<string> ignoreWord; 
    getStopWords(argv[3], ignoreWord); //problem with wrong parameter type //argv[3] //"HW2-stopwords.txt"
    
    
    ifstream writeFile; //create ofstream variable
    writeFile.open(argv[2]); //open file in Outputmode //arguement here //argv[2] //"HW2-HungerGames_edit.txt"
  
    wordItem* arrPoint = new wordItem[INITIAL_ARRAY_SIZE];
    
    int capacity = 0;
  
    string name;
    
    bool found1 = false;
    
    int currentSize = 100;
    
    int timesDoubled = 0;
    
    int uniqueNonStopWords = 0;
    
    int totalNonStopWords = 0;
    
    while(writeFile >> name){ //while there are still words being read in, continue
                
                if(isStopWord(name,ignoreWord)){
                    //do nothing, it is a stop word 
                }else{
                    
                    if(capacity == currentSize){
                        wordItem *copyArray = new wordItem[currentSize*2];
                        for(int i = 0; i < capacity; i++){
                            copyArray[i] = arrPoint[i];
                        }
                        delete []arrPoint;
                        arrPoint = copyArray;
                        
                        //doubleArray(arrPoint,currentSize);
                        currentSize = currentSize*2;
                        timesDoubled ++;
                    }
                    
                    found1 = addNonStop(arrPoint, capacity, name); //function to add a new word in 
                    if(found1 == true){
                        capacity++;
                        uniqueNonStopWords++;
                        totalNonStopWords++;
                    }else{
                        totalNonStopWords++;
                    }
            }
    }
    
    arraySort(arrPoint,capacity);
    
    
    printTopN(arrPoint, stoi(argv[1])); //arguement here //stoi(argv[1]) //10
    cout << "#" << endl;
    cout << "Array doubled: " << timesDoubled << endl;
    cout << "#" << endl;
    cout << "Unique non-stop words: " << uniqueNonStopWords << endl;
    cout << "#" << endl;
    cout << "Total non-stop words: " << totalNonStopWords << endl;
    
    
    // for(int i = 0; i < 50; i++){
        
    //     cout << ignoreWord[i] << endl;
    // }
    
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
    for(int i = 0; i < 50; i++){
        
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

bool addNonStop(wordItem arr1[], int capacity, string word1){
    
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
                    return true;
                }else{
                    arr1[foundIndex].count += 1;
                    found = false;
                    return false;
                }
}