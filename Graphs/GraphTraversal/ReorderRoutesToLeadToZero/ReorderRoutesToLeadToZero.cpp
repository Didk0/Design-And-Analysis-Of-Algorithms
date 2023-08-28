#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, bool>> graph[5 * 10001];
bool visited[5 * 10001];

void dfs(int start, vector<pair<int, bool>> graph[], int& count)
{
	visited[start] = true;
	for (size_t i = 0; i < graph[start].size(); i++)
	{
		if (!visited[graph[start][i].first])
		{
			count += graph[start][i].second;
			dfs(graph[start][i].first, graph, count);
		}
	}
}

int main()
{
	// условие: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

	int n = 6;
	vector<vector<int>> connections = { {0,1}, {1,3}, {2,3}, {4,0}, {4,5} };

	for (size_t i = 0; i < connections.size(); i++)
	{
		graph[connections[i][0]].push_back({ connections[i][1],1 });
		graph[connections[i][1]].push_back({ connections[i][0],0 });
	}

	int count = 0;

	dfs(0, graph, count);

	cout << count;

	return 0;
}
