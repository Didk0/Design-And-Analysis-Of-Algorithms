#include <iostream>
#include <vector>
using namespace std;

int parent[1001];
int height[1001];

int findRoot(int node)
{
	if (node != parent[node])
		parent[node] = findRoot(parent[node]);
	return parent[node];
}

void link(int root1, int root2)
{
	if (height[root1] == height[root2])
	{
		height[root1]++;
		parent[root2] = root1;
	}
	else if (height[root1] > height[root2])
		parent[root2] = root1;
	else
		parent[root1] = root2;
}

bool connected(int node1, int node2)
{
	int root1 = findRoot(node1);
	int root2 = findRoot(node2);
	if (root1 != root2)
	{
		link(root1, root2);
		return 0;
	}
	return 1;
}

int main()
{
	// условие: https://leetcode.com/problems/redundant-connection/description/

	vector<vector<int>> edges = { {1, 2},{2, 3},{3, 4},{1, 4},{1, 5} };

	for (int i = 1; i <= edges.size(); i++)
		parent[i] = i;

	vector<int> result(2);
	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		if (connected(u, v))
		{
			result[0] = u;
			result[1] = v;
		}
	}

	cout << "(" << result[0] << "," << result[1] << ")";

	return 0;
}
