#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void printFile(string fileName){
    
    ifstream writeFile; //create ofstream variable
	writeFile.open(fileName); //open the file
	
    if (writeFile.is_open())
    {                           //error check
        string data;
        while(getline(writeFile, data)){
            cout << data << endl;
        }
	   writeFile.close(); //close the file
    }
    else{
        
        cout << "File failed to open" << endl;
    }
}









int main(int argc, char* argv[]){
    
    printFile(argv[1]);
    
    return 0;
}