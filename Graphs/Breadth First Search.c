//Similar to tree traversal. Unlike trees, graphs might contain cycles. To avoid this we use a boolean visited array.
//It is assumed that all vertices are reachable from starting vertex

// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include<list>

using namespace std;

//using adjacency list represenation
class Graph
{
    int v; // number of vertices

    //pointer to array containing adjacency list
    list<int> *adj;

public:
    Graph(int V);

    void addEdge()


};
