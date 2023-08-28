#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using p = pair<int, int>; // (to, weight)

const int INF = INT_MAX;
bool used[10001];
int opt[10001];
vector<p> graph[10001] = { {{1,1},{2,2},{3,5},{6,8}}, {{0,1},{3,6},{4,7}}, {{0,2},{5,3},{6,1}},
 {{0,5}, {1,6}}, {{1,7}, {5,2}, {7,4}}, {{4,2},{7,3},{2,3}}, {{2,1}, {0,8}}, {{4,4},{5,3}} };
priority_queue<p, vector<p>, greater<p>> pq;

int main()
{
	fill(opt, opt + 10001, INF);
	opt[0] = 0;
	used[0] = 1;
	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		int curr = pq.top().second;
		used[curr] = 1;
		pq.pop();

		for (size_t i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i].first;

			if (!used[next])
			{
				if (opt[next] > opt[curr] + graph[curr][i].second)
				{
					opt[next] = opt[curr] + graph[curr][i].second;
					pq.push({ opt[next], next });
				}
			}
		}
	}

	for (int i = 0; i < 8; i++)
		cout << "0 -> " << i << " is " << opt[i] << endl;

	return 0;
}
