#include<iostream>
#include<climits>
#include<list>
#include "graph.hpp"
using namespace std;

Graph::Graph(){
    
}

Graph::~Graph(){
    
}

void Graph::addVertex(string _name){
    
    vertex newV; 
    
    newV.name = _name;
    newV.district = 0;
    newV.ID = 0;
    newV.visited = false;
    
    
    
    vertices.push_back(newV);
}

void Graph::addEdge(string v1, string v2, int distance)
{
    
    int foundInd = -1;
    int foundInd2 = -1;
    unsigned int i = 0;
    while(i < vertices.size()){
        
        if(vertices[i].name == v1){
            foundInd = i;
        }
        if(vertices[i].name == v2){
            foundInd2 = i;
        }
            
        i++; 
            
    }
    
    adjVertex one;
    
    one.v = &vertices[foundInd2];
    
    one.distance = distance;
    
    vertices[foundInd].adj.push_back(one);
    
}

void Graph::displayEdges(){
    
    unsigned int i = 0;
    while(i < vertices.size() ){
        
        cout << vertices[i].district <<":"<< vertices[i].name<< "-->";
            
            for(unsigned int z = 0; z < vertices[i].adj.size(); z++){
                
                cout << vertices[i].adj[z].v -> name << " (" << vertices[i].adj[z].distance << " miles)";
                
                if(z != (vertices[i].adj.size() - 1)){
                    cout << "***";
                }
                
            }
            cout << endl;
            i++;
        }
}
    
vertex * Graph::findVertex(string name){
    
    vertex * temp = NULL;
    
    for(unsigned int i = 0; i < vertices.size(); i++){
        
        if(vertices[i].name == name){
            *temp = vertices[i];
            return temp;
            
        }
    }
    
    return temp;
}

void Graph::BFTraversalLabel(string startingCity, int distID){
    
    int ind = -1;
    
    for(unsigned int i = 0; i < vertices.size(); i++){
        
        if(vertices[i].name == startingCity){
            ind = i;
            break;
        }
    }
    
    list<vertex*> queue;
    
    vertices[ind].visited = true;
    vertices[ind].district = distID;
    queue.push_back(&vertices[ind]);

    vertex* temporary;
    
    while(queue.empty() == false){
        
        temporary = queue.front();
        queue.pop_front();
        
        for(unsigned int z = 0; z < temporary -> adj.size(); z++){
            
            if(temporary -> adj[z].v-> district <= 0){
                temporary -> adj[z].v -> visited = true;
                temporary -> adj[z].v-> district = distID;
                queue.push_back(temporary -> adj[z].v);
            }
            
        }
        
    }
}
    
void Graph::assignDistricts(){
    
    int currID = 1;
    
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i].district == 0){
            BFTraversalLabel(vertices[i].name, currID);
            currID ++;
        }
        else{
            
        }
    }
    
}