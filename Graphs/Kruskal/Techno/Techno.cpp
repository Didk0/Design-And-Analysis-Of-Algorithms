#include <iostream>
#include <algorithm>
#include <vector>
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
	{}
};

int n, k, r;
vector<int> vertices[1001];
Edge edges[1001 * 1001];
int parent[1001];
int height[1001];

int findMinCategory(const vector<int>& v1, const vector<int>& v2)
{
	vector<int>::const_iterator p1 = v1.cbegin();
	vector<int>::const_iterator p2 = v2.cbegin();

	while (p1 != v1.cend() && p2 != v2.cend())
	{
		if (*p1 < *p2)
			++p1;
		else if (*p1 > *p2)
			++p2;
		else
			break;
	}

	if (p1 == v1.cend() || p2 == v2.cend())
		return k + 1;
	else
		return *p1;
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
	// условие: https://arena.olimpiici.com/#/catalog/319/problem/100893

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;

		cin >> r;

		for (int j = 0; j < r; j++)
		{
			int category;
			cin >> category;
			vertices[i].push_back(category);
		}
	}

	int ind = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int minCategory = findMinCategory(vertices[i], vertices[j]);
			edges[ind++] = Edge(i, j, minCategory);
		}
	}

	sort(edges, edges + ind, [](const Edge& e1, const Edge& e2) {
		return e1.weight < e2.weight;
		});

	int components = n, sum = 0;

	for (int i = 0; i < ind; i++)
	{
		if (!connected(edges[i].from, edges[i].to))
		{
			sum += edges[i].weight;
			components--;
		}
		if (components == 1)
			break;
	}

	cout << sum;

	return 0;
}
