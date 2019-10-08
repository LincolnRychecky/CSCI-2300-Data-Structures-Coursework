#include<iostream>
#include<climits>
#include<list>
#include "graph.hpp"
using namespace std;

Graph::Graph(int num)
{
    //this ->V = V;
    V = num;
    adj = new list<int> [V];
    
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::print(){
    
    list<int>::iterator itr;
    
    for(int i = 0; i < V; i++){
        cout << i << "->";
        for(itr = adj[i].begin(); itr!=adj[i].end();itr++){
            cout << *itr << ", ";
        }
        cout << endl;
    }
}

void Graph::BFS_helper(int s, bool visited[]){
    
    list<int> queue;
    list<int>::iterator itr;
    
    visited[s] = true;
    queue.push_back(s);
    
    while(queue.empty() == false){
        
        s = queue.front();
        cout << s << ", ";
        queue.pop_front();
        
        for(itr = adj[s].begin(); itr!=adj[s].end();itr++){
            if(visited[*itr] == false){
                visited[*itr] = true;
                queue.push_back(*itr);
            }
        }
    }
}

void Graph::BFS()
{

    bool visited[V];
    
    for(int i = 0; i < V; i++)
        visited[i] = false;
        
    for(int s = 0; s < V; s++){
        if(visited[s] == false)
            BFS_helper(s,visited);
    }
}

void Graph::DFS_helper(int s, bool visited[]){
    
     list<int> stack;
    list<int>::iterator itr;
    
    visited[s] = true;
    stack.push_back(s);
    
    while(stack.empty() == false){
        
        s = stack.back();
        cout << s << ", ";
        stack.pop_back();
        
        for(itr = adj[s].begin(); itr!=adj[s].end();itr++){
            if(visited[*itr] == false){
                visited[*itr] = true;
                stack.push_back(*itr);
            }
        }
    }
}

void Graph::DFS()
{

    bool visited[V];
    
    for(int i = 0; i < V; i++)
        visited[i] = false;
        
    for(int s = 0; s < V; s++){
        if(visited[s] == false)
            DFS_helper(s,visited);
    }

}