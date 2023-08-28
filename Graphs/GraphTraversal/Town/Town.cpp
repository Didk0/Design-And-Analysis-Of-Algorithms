#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

const int MAX = 200001;
queue<int> q;
vector<pair<int, bool>> graph[MAX];
bool visited[MAX];
int dist[MAX];
int n, a, b;
deque<int> deq;

int main()
{
	// условие: https://arena.olimpiici.com/#/catalog/192/problem/100458

	cin >> n >> a >> b;
	fill(dist, dist + n + 1, MAX);

	int from, to;
	while (cin >> from >> to)
	{
		graph[from].push_back({ to,0 });
		graph[to].push_back({ from,1 });
	}

	deq.push_back(a);
	dist[a] = 0;

	while (!deq.empty())
	{
		int currNode = deq.front();
		deq.pop_front();
		visited[currNode] = true;

		for (const pair<int, bool>& neighbour : graph[currNode])
		{
			if (!visited[neighbour.first])
			{
				if (neighbour.second == 1)
				{
					deq.push_back(neighbour.first);
				}
				else
				{
					deq.push_front(neighbour.first);
					visited[neighbour.first] = true;
				}
				if (dist[neighbour.first] > dist[currNode] + neighbour.second)
					dist[neighbour.first] = dist[currNode] + neighbour.second;
			}
		}
	}

	if (dist[b] != MAX)
		cout << dist[b];
	else
		cout << "X";

	/* II решение:
	bool reached = false;
	dist[a] = 0;
	q.push(a);

	while (!q.empty())
	{
		int currNode = q.front();
		q.pop();

		if (currNode == b)
		{
			reached = true;
		}

		if (!visited[currNode])
		{
			for (size_t i = 0; i < graph[currNode].size(); i++)
			{
				if (!visited[graph[currNode][i].first])
					dist[currNode] = min(dist[currNode], dist[graph[currNode][i].first] + !graph[currNode][i].second);
			}
		}

		for (size_t i = 0; i < graph[currNode].size(); i++)
		{
			if (!visited[graph[currNode][i].first])
			{
				if (dist[currNode] + graph[currNode][i].second < dist[graph[currNode][i].first])
				{
					dist[graph[currNode][i].first] = dist[currNode] + graph[currNode][i].second;
					q.push(graph[currNode][i].first);
				}
			}
		}
		visited[currNode] = 1;
	}

	if (!reached)
		cout << "X";
	else
		cout << dist[b];*/

	return 0;
}
