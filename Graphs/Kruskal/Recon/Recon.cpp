#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
	Edge(int f = 0, int t = 0, int w = 0)
		: from(f)
		, to(t)
		, weight(w)
	{};
};

int n;
Edge edges[1024 * 1024];
int parent[1030];
int height[1030];

void init()
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
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
	// условие: https://arena.olimpiici.com/#/catalog/30/problem/100049

	cin >> n;

	int m = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int weight;
			cin >> weight;

			edges[m].from = i;
			edges[m].to = j;
			edges[m++].weight = weight;
		}
	}

	sort(edges, edges + m, [](const Edge& e1, const Edge& e2) {
		return e1.weight < e2.weight;
		});

	init();

	int components = n, ind = 0;
	vector<set<int>> result(n + 1);

	for (int i = 0; i < m; i++)
	{
		if (!connected(edges[i].from, edges[i].to))
		{
			components--;
			result[edges[i].from].insert(edges[i].to);
			result[edges[i].to].insert(edges[i].from);
		}

		if (components == 1)
			break;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i].size();

		for (int neighbour : result[i])
			cout << ' ' << neighbour;

		cout << endl;
	}

	return 0;
}