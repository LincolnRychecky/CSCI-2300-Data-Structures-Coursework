#include <iostream> //cin, cout, endl
#include <fstream> //ifstream
#include <string> //string
#include <sstream> //stringstream

//command line notes

//g++ -std=c++11 (name of file.cpp) -o (what you want it to be called "cmdarg_program")
//./(NAME OVF ALLIAS) input input input, etc...
//always have to recompile after changing code
//int main(int argc, char* argv[])
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
    
    int count = 0;
    int copy[100] = {};
    int location;
    
        while((myArray[count] < newValue) && (myArray[count] != 0)){ //find index where new value will go
            count ++;
        }
        
            location = count; //set location where new value will go to count
            while(count < numEntries){ //create a copy of the array from the location to the right until you hit the last value
                copy[count + 1] = myArray[count];
                count ++;
            }
        
        int copyCount = location; //create a counter to help set all values in the original to the copy. right shift
        while(copyCount < numEntries+1){
            
            myArray[copyCount] = copy[copyCount];
            copyCount++;
        }
        myArray[location] = newValue; //now set the index where the new value should go to that new value
    
    numEntries++; //increment number of entries by 1
    
    return numEntries; //return how many entries that there now are
}




int main(int argc, char* argv[]) {
    
    int arr1[100] = {}; //creating int array with size of 100
    int noe = 0; //number of entries variable
    //cout << argv[1] << endl; //print file name you input in command line
    
    ifstream writeFile; //create ifstream variable
	writeFile.open(argv[1]); //open the file specified in the command line argument
	    
	string line1;    
	int holder;
	
	while(getline(writeFile, line1)){
	    
	    holder = stoi(line1);
	    
	    insertIntoSortedArray(arr1, noe, holder);
	    noe++;
    	for(int i = 0; i < noe; i++){
            cout << arr1[i] << " ";
           }
        cout << endl;
	    
	}
	    
	cout << "What number are you looking for?"<<endl;
	string choice;
	getline(cin, choice);
	int choiceConverted = stoi(choice);
	for(int z = 0; z < noe; z++){
	    
	    if(arr1[z] == choiceConverted){
	        cout << choice << " is located at index "<< z << endl;
	        break;
	    }
	    
	}
    
  
    writeFile.close();
    
    
 return 0;
}