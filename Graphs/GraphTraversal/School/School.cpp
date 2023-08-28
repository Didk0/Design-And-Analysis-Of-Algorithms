#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<int> graph[501];
bool visited[501];
int components = 0;

void dfs(int vertex)
{
	visited[vertex] = true;
	for (int neighbour : graph[vertex])
	{
		if (!visited[neighbour])
		{
			dfs(neighbour);
		}
	}
}

int main()
{
	// условие: https://judge.openfmi.net/practice/open_contest?contest_id=178 школа

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			components++;
		}
	}

	cout << components;

	return 0;
}
