#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	// условие: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

	int n = 8;
	vector<vector<int>> edges = { {0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6} };

	vector<int> graph[500];
	int inDegrees[500] = { 0, };
	vector<int> topSort;
	vector<set<int>> ancestors(n);

	for (size_t i = 0; i < edges.size(); i++)
	{
		graph[edges[i][0]].push_back(edges[i][1]);
		inDegrees[edges[i][1]]++;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (inDegrees[i] == 0)
		{
			topSort.push_back(i);
		}
	}

	for (size_t i = 0; i < topSort.size(); i++)
	{
		int curr = topSort[i];

		for (size_t j = 0; j < graph[curr].size(); j++)
		{
			for (size_t k : ancestors[curr])
			{
				ancestors[graph[curr][j]].insert(k);
			}
			ancestors[graph[curr][j]].insert(curr);

			inDegrees[graph[curr][j]]--;
			if (inDegrees[graph[curr][j]] == 0)
				topSort.push_back(graph[curr][j]);
		}
	}

	vector<vector<int>> result(n);
	for (size_t i = 0; i < result.size(); i++)
	{
		for (int el : ancestors[i])
			result[i].push_back(el);
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		for (size_t j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
