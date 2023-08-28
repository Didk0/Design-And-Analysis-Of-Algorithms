#include <iostream>
#include <algorithm>
#include <climits>
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

struct Vertex
{
	int to;
	int weight;
	Vertex(int t = 0, int w = 0)
		: to(t)
		, weight(w)
	{}
};

const int MAX = 200;

int n, m, k;
Edge edges[100000];
vector<Vertex> graph[1001];
int parent[1001];
int height[1001];
int visited[1001];
pair<int, int> pairs[10000];

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

bool dfs(int src, int dst, int& min)
{
	if (src == dst)
		return true;

	visited[src] = true;

	for (size_t i = 0; i < graph[src].size(); i++)
	{
		if (!visited[graph[src][i].to])
		{
			if (dfs(graph[src][i].to, dst, min))
			{
				min = std::min(min, graph[src][i].weight);
				visited[src] = false;
				return true;
			}
		}
	}

	visited[src] = false;
	return false;
}

int main()
{
	//cin >> n >> m >> k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
	//cin >> edges[i].from >> edges[i].to >> edges[i].weight;

	sort(edges, edges + m, [](const Edge& e1, const Edge& e2) {
		return e1.weight > e2.weight;
		});

	int components = n;

	for (int i = 0; i < m; i++)
	{
		if (!connected(edges[i].from, edges[i].to))
		{
			components--;
			graph[edges[i].from].push_back({ edges[i].to, edges[i].weight });
			graph[edges[i].to].push_back({ edges[i].from, edges[i].weight });
		}
		if (components == 1)
			break;
	}

	for (int i = 0; i < k; i++)
		scanf("%d%d", &pairs[i].first, &pairs[i].second);

	for (int i = 0; i < k; i++)
	{
		int minWidth = MAX;

		dfs(pairs[i].first, pairs[i].second, minWidth);

		//cout << minWidth << endl;
		printf("%d\n", minWidth);
	}

	return 0;
}
