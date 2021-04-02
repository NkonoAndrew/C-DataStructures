#include <queue>
#include <list>
#include <iostream>
using namespace std;


// traces parent pointers back from endv to startv
void printPath(int parents[], int size, int startv, int endv) {
	if (endv != startv)
		printPath(parents, size, startv, parents[endv]);
	cout << endv << " ";
}


void bfs (vector<int> alists[], int size, int start, int target) {
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
		printPath(parents,size,start,target);
	else
		cout << "Not found";
	cout << endl;
	delete [] parents;
}

int main () {
	const int size = 10;
	vector<int> alists[size];
//	  alists[0].push_back(1);
	alists[0].push_back(2);
	alists[1].push_back(0);
	alists[1].push_back(3);
	alists[2].push_back(0);
	alists[2].push_back(4);
	alists[3].push_back(1);
	alists[3].push_back(4);
	alists[3].push_back(5);
	alists[3].push_back(6);
	alists[4].push_back(2);
	alists[4].push_back(7);
//	  alists[5].push_back(3);
	alists[5].push_back(6);
	alists[5].push_back(8);
	alists[6].push_back(3);
	alists[6].push_back(5);
	alists[7].push_back(4);
	alists[7].push_back(8);
	alists[8].push_back(5);
	alists[8].push_back(7);
	alists[9].push_back(6);
	alists[9].push_back(7);
	bfs(alists,size,0,9);
	bfs(alists,size,9,0);
	bfs(alists,size,0,1);
	bfs(alists,size,1,0);
	return 0;
}

