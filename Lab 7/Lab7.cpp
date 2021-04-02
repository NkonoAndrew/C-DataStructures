#include<iostream>
#include<fstream>
#include <queue>
#include <list>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<conio.h>

using namespace std;
struct Graph
{
    string city;
    string country;
};




int main()
{
    int index;
    ifstream inFile;
    inFile.open("chicken.txt");

    string words;

    if (!inFile)
        {
            cout << "\nSorry, the data file \"connections.txt\" was not found on this drive";
            cout << "\n\nHit Any Key to continue";
            getch();
            system("cls");
        }
        inFile >> words;


 /*
*/
}

void bfs (vector<int> alists[], int size, int start, int target)
{
	int * parents = new int[size];
	for (int i = 0; i< size; i++) parents[i] = -1;
	parents[start] = start;
	queue<int> q;
	q.push(start);
	bool found = false;
	while (!q.empty() && !found) {
		int v = q.front();
		q.pop();
		if (v == target)
			found = true;

		else for (int i = 0; i < alists[v].size(); i++) {
			int w = alists[v][i];
			if (parents[w] == -1) {
				parents[w] = v;
				q.push(w);
			}
		}
	}
	if (found)
//		printPath(parents,size,start,target);
	else
		cout << "Not found";
	cout << endl;
	delete [] parents;
}

void printPath(int parents[], int size, int startv, int endv)
{
	if (endv != startv)
		printPath(parents, size, startv, parents[endv]);
	cout << endv << " ";
}
