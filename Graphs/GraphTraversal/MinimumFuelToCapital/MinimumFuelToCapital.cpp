#include <iostream>
#include <vector>
using namespace std;

bool visited[100005];
vector<int> graph[100005];

int dfs(int start, int& fuel, vector<int> graph[], int seats)
{
	visited[start] = 1;
	int people = 1;

	for (size_t i = 0; i < graph[start].size(); i++)
	{
		if (!visited[graph[start][i]])
			people += dfs(graph[start][i], fuel, graph, seats);
	}

	if (start != 0)
		fuel += people / seats + (people % seats == 0 ? 0 : 1);

	return people;
}

int main()
{
	// условие: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/

	int seats = 2;
	vector<vector<int>> roads = { {3,1} ,{3,2},{1,0},{0,4},{0,5},{4,6} };
	
	for (size_t i = 0; i < roads.size(); i++)
	{
		graph[roads[i][0]].push_back(roads[i][1]);
		graph[roads[i][1]].push_back(roads[i][0]);
	}

	int fuel = 0;
	dfs(0, fuel, graph, seats);

	cout << fuel;

	return 0;
}
