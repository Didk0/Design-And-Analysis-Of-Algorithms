#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge
{
	long long int to;
	long long int points;
	long long int time;
};

using p = pair<long long int, long long int>;

const long long int INF = LLONG_MIN;
long long int n, m, k;
vector<Edge> graph[2 * 10005];
long long int dist[2 * 10005];
bool visited[2 * 10005];
priority_queue<p, vector<p>, less<p>> pq;

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		long long int from;
		cin >> from;
		Edge e;
		cin >> e.to >> e.points >> e.time;
		graph[from].push_back(e);
		graph[e.to].push_back({from, e.points, e.time});
	}

	fill(dist, dist + n + 1, INF);

	dist[1] = k;
	pq.push({ k, 1 });

	while (!pq.empty())
	{
		long long int currNode = pq.top().second;
		visited[currNode] = true;
		pq.pop();

		for (size_t i = 0; i < graph[currNode].size(); i++)
		{
			long long int next = graph[currNode][i].to;
			long long int pointsToLose = graph[currNode][i].time - graph[currNode][i].points;

			if (!visited[next])
			{
				long long int currPoints = dist[currNode] - pointsToLose;
				
				if (currPoints > dist[next])
				{
					dist[next] = currPoints;
					pq.push({ dist[next], next });
				}
			}
		}
	}

	cout << dist[n];

	return 0;
}
