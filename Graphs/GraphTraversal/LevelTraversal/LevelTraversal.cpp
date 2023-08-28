#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int VERTICES = 1024;
int n, m;
vector<int> gr[VERTICES];
bool used[VERTICES];
queue<int> spis;
int levels[VERTICES];


void bfs(int start)
{
	used[start] = 1;
	spis.push(start);
	int level = 1;
	levels[start] = 1;
	int nodesOfLevel = 1;
	while (!spis.empty())
	{
		int node = spis.front();
		spis.pop();
		nodesOfLevel--;
		levels[node] = level;
		for (int i = 0; i < gr[node].size(); i++)
		{
			if (!used[gr[node][i]])
			{
				used[gr[node][i]] = 1;
				spis.push(gr[node][i]);
			}
		}
		if (nodesOfLevel == 0)
		{
			level++;
			nodesOfLevel = spis.size();
		}
	}
}

int main()
{
	/*
	10 13
	1 2
	1 4
	1 3
	1 5
	2 6
	3 4
	3 5
	4 6
	5 10
	5 8
	6 7
	7 8
	8 9

	*/
	cin >> n >> m;
	int from, to;
	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		gr[from].push_back(to);
		gr[to].push_back(from);
	}
	bfs(1);
	for (int i = 1; i <= n; i++)
	{
		cout << levels[i] << ' ';
	}
	cout << endl;

	return 0;
}
