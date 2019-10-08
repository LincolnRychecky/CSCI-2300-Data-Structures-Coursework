#include "graph.hpp"
#include<iostream>
#include<set>
#include<list>
#include<algorithm>
using namespace std;


Graph::Graph(int nodeCount) {
   n = nodeCount;
   adjList = new list<node>[n];
}

void Graph::showList(int src, list<node> lt) {
   list<node> :: iterator i;
   node tempNode;

   for(i = lt.begin(); i != lt.end(); i++) {
      tempNode = *i;
      cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
   }
   cout << endl;
}



void Graph::addEdge(int source, int dest, int cost)
{
   node newNode;
   newNode.dest = dest;
   newNode.cost = cost;
   adjList[source].push_back(newNode);

   node newNode1;
   newNode1.dest = source;
   newNode1.cost = cost;
   adjList[dest].push_back(newNode1);
}

void Graph::displayEdges()
{
   for(int i = 0; i<n; i++)
   {
      list<node> tempList = adjList[i];
      showList(i, tempList);
   }
}

int Graph:: min_element(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < n; v++)
   {
     if (visited[v] == false && dist[v] <= min)
     {
         min = dist[v];
          min_index = v;
      }
  }

   return min_index;
}
void Graph::dijkstra( int *dist, int *prev, int start) {

   bool visited[n];
   for(int u = 0; u<n; u++) {
      dist[u] = 9999;   //set as infinity
      prev[u] = -1;    //undefined previous
      visited[u] = false;
   }

   dist[start] = 0;   //distance of start is 0
   //visited[start] = true;
   set<int> S;       //create empty set S
   list<int> Q;

   for(int count = 0; count < n-1; count++)
    {

      int u = min_element(dist,visited);
      visited[u] = true;
      list<node> :: iterator it;

      for(it = adjList[u].begin(); it != adjList[u].end();it++)
      {
         if((dist[u]+(it->cost)) < dist[it->dest])
         { //relax (u,v)
            dist[it->dest] = (dist[u]+(it->cost));
            prev[it->dest] = u;
         }
      }
   }
}



