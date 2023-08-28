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

Edge edges[10001];
int parent[1001];
int height[1001];

void makeSets()
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		height[i] = 0;
	}
}

int findSet(int node)
{
	if (node == parent[node])
	{
		return node;
	}
	return parent[node] = findSet(parent[node]);
}

void unionSet(int root1, int root2)
{
	if (height[root1] < height[root2])
	{
		swap(root1, root2);
	}
	else if (height[root1] == height[root2])
	{
		height[root1]++;
	}
	parent[root2] = root1;
}

int main()
{
	// условие: https://action.informatika.bg/problems/78

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;
	}

	sort(edges, edges + m, [](const Edge& e1, const Edge& e2) {
		return e1.weight < e2.weight;
		});

	int low = 0, high = 30001;

	for (int i = 0; i < m; i++)
	{
		makeSets();
		int components = n;

		for (int j = i; j < m; j++)
		{
			Edge edge = edges[j];
			int root1 = findSet(edge.from);
			int root2 = findSet(edge.to);

			if (root1 != root2)
			{
				unionSet(root1, root2);
				--components;
				if (components == 1)
				{
					int currLow = edges[i].weight;
					int currHigh = edge.weight;

					if (currHigh - currLow < high - low)
					{
						low = currLow;
						high = currHigh;
					}

					break;
				}
			}
		}
	}

	cout << low << ' ' << high;

	return 0;
}