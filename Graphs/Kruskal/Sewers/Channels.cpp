#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;
};

vector<Edge> edges;
int parent[100000];
int height[100000];
int n, m, k;

int findRoot(int node)
{
	if (node != parent[node])
	{
		parent[node] = findRoot(parent[node]);
	}
	return parent[node];
}

void link(int root1, int root2)
{
	if (height[root1] == height[root2])
	{
		height[root1] += 1;
		parent[root2] = root1;
	}
	else if (height[root1] < height[root2])
	{
		parent[root1] = root2;
	}
	else
	{
		parent[root2] = root1;
	}
}

int main()
{
	// условие: https://arena.olimpiici.com/#/catalog/42/problem/100081

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int f, t, w;
		cin >> f >> t >> w;
		Edge e;
		e.from = f;
		e.to = t;
		e.weight = w;
		edges.push_back(e);
	}

	cin >> k;

	sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
		return e1.weight > e2.weight;
		});

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int ans = 0, components = n;
	for (int i = 0; i < m; i++)
	{
		int root1 = findRoot(edges[i].from);
		int root2 = findRoot(edges[i].to);
		if (root1 != root2)
		{
			link(root1, root2);
			if (edges[i].weight < k)
			{
				ans++;
			}
			components--;
		}
		if (components == 1)
			break;
	}

	cout << ans;

	return 0;
}