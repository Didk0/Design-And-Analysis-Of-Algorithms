#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
};

int n, m;
Edge edges[100005];
int parent[10005];
int height[10005];

void init()
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		height[i] = 0;
	}
}

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
	// условие: https://action.informatika.bg/problems/115

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;
	}

	sort(edges, edges + m, [](const Edge& e1, const Edge& e2) {
		return e1.weight < e2.weight;
		});

	init();
	long long int sum = 0;
	int components = n;

	for (int i = 0; i < m; i++)
	{
		if (!connected(edges[i].from, edges[i].to))
		{
			components--;
		}
		else
		{
			sum += edges[i].weight;
		}
	}

	cout << (components == 1 ? sum : -1);

	return 0;
}