#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using p = pair<long long int, long long int>;

struct Edge
{
	long long int to;
	long long int seconds;
	long long int green;
	long long int red;
};

const long long int INF = LLONG_MAX;

bool visited[100001];
long long int dist[100001];
priority_queue<p, vector<p>, greater<p>> pq;
vector<Edge> graph[100001];

long long int n, m;
long long int s;

int main()
{
	// условие: https://arena.olimpiici.com/#/catalog/756/problem/101958

	cin >> n >> m >> s;

	for (long long int i = 0; i < m; i++)
	{
		long long int from;
		cin >> from;
		Edge e;
		cin >> e.to >> e.seconds >> e.green >> e.red;

		graph[from].push_back(e);
		graph[e.to].push_back({ from, e.seconds, e.green, e.red });
	}

	fill(dist, dist + n + 1, INF);

	dist[1] = s;
	pq.push({ s, 1 });

	while (!pq.empty())
	{
		long long int curr = pq.top().second;
		visited[curr] = true;
		pq.pop();

		for (const Edge& neighbour : graph[curr])
		{
			if (!visited[neighbour.to])
			{
				long long int currSec = dist[curr];

				long long int secondsToWait = currSec % (neighbour.red + neighbour.green);

				if (0 <= secondsToWait && secondsToWait <= neighbour.green - 1)
					secondsToWait = 0;
				else if (neighbour.green <= secondsToWait && secondsToWait <= neighbour.red + neighbour.green - 1)
				{
					secondsToWait = (neighbour.red + neighbour.green - 1) - secondsToWait + 1;
				}

				currSec += neighbour.seconds + secondsToWait;

				if (currSec < dist[neighbour.to])
				{
					dist[neighbour.to] = currSec;
					pq.push({ dist[neighbour.to], neighbour.to });
				}
			}
		}
	}

	for (long long int i = 2; i <= n; i++)
	{
		cout << dist[i] << ' ';
	}

	return 0;
}
