#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "MovieTree.hpp"
using namespace std;

int main(int argc, char *argv[]){
//new movie tree initalized
MovieTree newTree;

ifstream writeFile; //create ofstream variable
writeFile.open(argv[1]); //open file in Outputmode

string line;
string chunk;
string name;
int year;
int quantity;
int rating;

while(getline(writeFile,line)){
    stringstream ss(line);   
    int i = 0;
    while(getline(ss, chunk, ',')){
        if(i == 0){
            rating = stoi(chunk);
        }
        if(i == 1){
            name = chunk;
        }
        if(i == 2){
            year = stoi(chunk);
        }
        if(i == 3){
            quantity = stoi(chunk);
        }
        i++;
    }
    
    newTree.addMovieNode(rating, name, year, quantity);
    
}

writeFile.close();

cout << "======Main Menu======" << endl;
cout << "1. Find a movie" << endl;
cout << "2. Rent a movie" << endl;
cout << "3. Print the inventory" << endl;
cout << "4. Quit" << endl;

string choice;

getline(cin, choice);

while(choice != "4"){
    
    if(choice == "1"){
        string choice1;
        cout << "Enter title:" << endl;
        getline(cin, choice1);
        newTree.findMovie(choice1);
    }
    
    else if(choice == "2"){
        string choice2;
        cout << "Enter title:" << endl;
        getline(cin, choice2);
        newTree.rentMovie(choice2);
    }
    
    else if(choice == "3"){
        newTree.printMovieInventory();
    }
    
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Quit" << endl;
    getline(cin, choice);
    
}

cout << "Goodbye!" << endl;


return 0;
}