#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Edge
{
	int from;
	int to;
	int length;
	int cost;
};

int n, m;
int costPerOne[10005];
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
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> costPerOne[i];

	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].length;
		if (edges[i].length % 2 == 0)
		{
			int half = edges[i].length / 2;
			edges[i].cost = costPerOne[edges[i].from] * half + costPerOne[edges[i].to] * half;
		}
		else
		{
			int half = edges[i].length / 2 + 1;
			int rest = edges[i].length - half;
			int smallerNum = min(edges[i].from, edges[i].to);
			int biggerNum = max(edges[i].from, edges[i].to);
			edges[i].cost = costPerOne[smallerNum] * half + costPerOne[biggerNum] * rest;
		}
	}

	sort(edges, edges + m, [](const Edge& e1, const Edge& e2) {
		return e1.cost < e2.cost;
		});

	init();

	int components = n;
	long long int sum = 0;
	set<pair<int, int>> resEdges;
	for (int i = 0; i < m; i++)
	{
		if (!connected(edges[i].from, edges[i].to))
		{
			components--;
			sum += edges[i].cost;
			int from = edges[i].from, to = edges[i].to;
			if (from > to)
				swap(from, to);
			resEdges.insert({ from, to });
		}
		if (components == 1)
			break;
	}

	cout << sum << endl;
	for (const auto& e : resEdges)
		cout << e.first << ' ' << e.second << endl;
}
