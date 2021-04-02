#include<iostream>
#include <vector>
using namespace std;

//Undirected Graph
void addEdge( vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void print( vector<int> adj[])
{
    for (int v = 0; v < 5; v++ )
    {
        cout << "\n For a list with header " << v << ", the list is ";
        for (auto x : adj[v])
        {
            cout << "->" << x;

        }
    }

}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    print(adj);
}




