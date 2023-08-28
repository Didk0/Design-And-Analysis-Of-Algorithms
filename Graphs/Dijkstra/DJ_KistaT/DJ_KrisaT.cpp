#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using p = pair<int, int>; // (to, weight)
struct Edge
{
	int to;
	int price;
	int time;
	Edge(int to, int price, int time)
		: to(to)
		, price(price)
		, time(time)
	{}
};

int n, m, k;
const long long INF = 1000000000000;
bool visited[100001];
long long dist[100001];
vector<Edge> graph[100001];
priority_queue<p, vector<p>, greater<p>> pq;

bool good(int maxTicket)
{
	fill(dist, dist + 100001, INF);

	dist[1] = 0;
	pq.push({ 0, 1 });
	
	while (!pq.empty())
	{
		int curr = pq.top().second;
		visited[curr] = 1;
		pq.pop();

		for (size_t i = 0; i < graph[curr].size(); i++)
		{
			if (!visited[graph[curr][i].to] && graph[curr][i].price <= maxTicket)
			{
				if (dist[graph[curr][i].to] > dist[curr] + graph[curr][i].time)
				{
					dist[graph[curr][i].to] = dist[curr] + graph[curr][i].time;
					pq.push({ dist[graph[curr][i].to], graph[curr][i].to });
				}
			}
		}
	}

	fill(visited, visited + 100001, 0);

	return dist[n] <= k;
}

int main()
{
	// условие: https://action.informatika.bg/problems/151

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int a, b, p, t;
		cin >> a >> b >> p >> t;
		graph[a].push_back(Edge(b, p, t));
	}

	int l = 1, r = 1000000;
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (good(m))
			r = m - 1;
		else
			l = m + 1;
	}

	cout << (l == 1000000 + 1 ? -1 : l);

	return 0;
}
