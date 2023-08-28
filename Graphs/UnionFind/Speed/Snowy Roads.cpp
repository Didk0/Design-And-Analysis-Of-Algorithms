#include <iostream>
#include <vector>
using namespace std;

pair<int, int> edges[300005];
int n, m;
int parent[100005];
int depth[100005];

int findRoot(int node)
{
	if (node != parent[node])
		parent[node] = findRoot(parent[node]);
	return parent[node];
}

void link(int root1, int root2)
{
	if (depth[root1] == depth[root2])
	{
		depth[root1] += 1;
		parent[root2] = root1;
	}
	else if (depth[root1] > depth[root2])
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
	// условие: https://action.informatika.bg/problems/158

	cin >> n >> m;
	int components = n;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	int stop = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].first >> edges[i].second;

		if (!connected(edges[i].first, edges[i].second))
		{
			stop = i + 1;
			components--;
		}
	}

	cout << (components > 1 ? -1 : stop);

	return 0;
}