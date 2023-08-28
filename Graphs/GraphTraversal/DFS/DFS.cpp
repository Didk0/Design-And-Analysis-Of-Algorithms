#include <iostream>
#include <vector>
using namespace std;

const int VERTICES = 1024;
int n, m; // върхове, ребра
int source, sink; // source - начален връх, sink - краен връх
vector<int> graph[VERTICES];

bool used[VERTICES];

void dfs(int vertex)
{
	used[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++)
	{
		if (!used[graph[vertex][i]])
		{
			dfs(used[graph[vertex][i]]);
		}
	}
}

int main()
{
	cin >> n >> m;
	int from, to;
	for (int i = 0; i <= m; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	cin >> source >> sink;

	dfs(source);
	if (used[sink] == 1)
		cout << "There is a path" << endl;

	return 0;
}