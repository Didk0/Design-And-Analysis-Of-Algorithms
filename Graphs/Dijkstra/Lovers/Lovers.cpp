#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using p = pair<int, int>;

const int INF = INT_MAX;
bool used[10005];
int opt[10005];
priority_queue<p, vector<p>, greater<p>> pq;
vector<p> graph[10005];
int minutes[10005];
int parent[10005];

int main()
{
	// условие: https://action.informatika.bg/problems/100

	fill(opt, opt + 10005, INF);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> minutes[i];

	for (int i = 0; i < m; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to, weight });
	}

	opt[1] = 0;
	pq.push({ 0, 1 });
	parent[1] = 1;
	while (!pq.empty())
	{
		int currNode = pq.top().second;
		used[currNode] = true;
		pq.pop();

		for (size_t i = 0; i < graph[currNode].size(); i++)
		{
			int next = graph[currNode][i].first;
			int edgeCost = graph[currNode][i].second;

			if (!used[next])
			{
				int currPath = opt[currNode] + edgeCost;

				if (next != n)
				{
					int minutesToWait = minutes[next] - (currPath % minutes[next] == 0 ? minutes[next] : currPath % minutes[next]);
					currPath += minutesToWait;
				}

				if (currPath < opt[next])
				{
					parent[next] = currNode;
					opt[next] = currPath;
					pq.push({ opt[next], next });
				}
			}
		}
	}
	if (opt[n] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << opt[n] << endl;
		int node = n;
		vector<int> path;
		path.push_back(node);
		while (node != parent[node])
		{
			node = parent[node];
			path.push_back(node);
		}
		cout << path.size() << endl;
		for (size_t i = 0; i < path.size(); i++)
			cout << path[path.size() - 1 - i] << ' ';
	}

	return 0;
}
