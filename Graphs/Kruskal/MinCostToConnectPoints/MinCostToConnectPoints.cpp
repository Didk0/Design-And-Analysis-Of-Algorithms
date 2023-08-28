#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
};

Edge edges[1000 * 1000];
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
		height[root1] += 1;
		parent[root2] = root1;
	}
	else if (height[root1] > height[root2])
	{
		parent[root2] = root1;
	}
	else
	{
		parent[root1] = root2;
	}
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
	// условие: https://leetcode.com/problems/min-cost-to-connect-all-points/description/

	vector<vector<int>> points = { {0, 0},{2, 2},{3, 10},{5, 2},{7, 0} };

	for (size_t i = 0; i < points.size(); i++)
		parent[i] = i;

	int m = 0;

	for (size_t i = 0; i < points.size(); i++)
	{
		for (size_t j = i + 1; j < points.size(); j++)
		{
			edges[m].from = i;
			edges[m].to = j;
			edges[m++].weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
		}
	}

	sort(edges, edges + m, [](const Edge& e1, const Edge& e2) {
		return e1.weight < e2.weight;
		});

	int components = points.size(), cost = 0;

	for (int i = 0; i < m; i++)
	{
		if (!connected(edges[i].from, edges[i].to))
		{
			components--;
			cost += edges[i].weight;
		}

		if (components == 1)
			break;
	}

	cout << cost;

	return 0;
}
