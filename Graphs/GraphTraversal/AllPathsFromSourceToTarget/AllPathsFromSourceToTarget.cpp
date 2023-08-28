#include <iostream>
#include <vector>
using namespace std;

bool visited[16];

void dfsAndCountPaths(int src, vector<int>& currPath, vector<vector<int>>& paths,
	vector<vector<int>>& graph)
{
	currPath.push_back(src);
	visited[src] = true;
	if (src == graph.size() - 1)
		paths.push_back(currPath);
	for (int i = 0; i < graph[src].size(); i++)
	{
		if (!visited[graph[src][i]])
			dfsAndCountPaths(graph[src][i], currPath, paths, graph);
	}

	visited[src] = false;
	currPath.pop_back();
}

int main()
{
	// условие: https://leetcode.com/problems/all-paths-from-source-to-target/

	vector<vector<int>> graph = { {4, 3, 1},{3, 2, 4},{3},{4},{} };
	vector<vector<int>> paths;
	vector<int> startPath;
	dfsAndCountPaths(0, startPath, paths, graph);

	// return paths;

	return 0;
}
