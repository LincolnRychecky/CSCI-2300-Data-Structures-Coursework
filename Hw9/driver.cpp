#include<iostream>
#include<climits>
#include<list>
#include <sstream>
#include <fstream>
#include <string>
#include "graph.hpp"
using namespace std;

//g++ -std=c++11 graph.cpp driver.cpp -o prgm1

int main(int argc, char *argv[]){
    
    Graph p;
    
    string cities [15]; //array to hold city names
    int distances [15][15];
    
    ifstream readFile; //create ofstream variable
                
    readFile.open(argv[1]);
    
    string line;
    string chunk;
    
     getline(readFile,line);
     stringstream ss(line);
     int iy = 0;
     while(getline(ss, chunk, ',')){
        if(chunk == "cities"){
            
        }else{
            cities[iy] = chunk;    
            
            iy++;
        }
     }
    
    
    
    
    
    
    
    
    int linenum = 0;
    while(getline(readFile,line)){
        stringstream ss(line);
        int z = 0;
        int timesThrough = 0;;
        while(getline(ss, chunk, ',')){
                if(timesThrough == 0){
                    
                }
                else{
                    distances[linenum][z] = stoi(chunk);    
                    z++;
                }
                timesThrough++;
            }
        linenum++;
    }
    
    for(int i = 0; i < iy; i++){
        
        p.addVertex(cities[i]);
        
    }
    
    for(int i = 0; i < iy ; i++){
        
        for(int z = 0; z < iy; z++){
            
            if( distances[i][z] > 0){
                
                cout << " ... Reading in " << cities[i] << " -- " << cities[z] << " -- " << distances[i][z] << endl;
                p.addEdge(cities[i], cities[z], distances[i][z]);
                
            }
            
        }
        
    }
    
    p.assignDistricts();
    p.displayEdges();
    
    
    
     
    
    
    readFile.close();
    
    
    return 0;
}