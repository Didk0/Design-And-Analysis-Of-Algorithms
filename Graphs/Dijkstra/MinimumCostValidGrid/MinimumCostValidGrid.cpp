#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using coord = pair<int, int>;
using p = pair<int, coord>;

int horizontal[4] = { 0, 0, 1, -1 };
int vertical[4] = { 1, -1, 0, 0 };

const int INF = 100000;
int dist[10005];
bool visited[10005];
priority_queue<p, vector<p>, greater<p>> pq;

vector<vector<int>> grid = { {1, 1, 1, 1},{2, 2, 2, 2},{1, 1, 1, 1},{2, 2, 2, 2} };
//vector<vector<int>> grid = { {1, 1, 3},{3, 2, 2},{1, 1, 4} };
//vector<vector<int>> grid = { {1, 2},{4, 3} };

int m = (int)grid[0].size(), n = (int)grid.size();

bool isValid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main()
{
	// условие: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

	fill(dist, dist + 10005, INF);

	dist[0] = 0;
	pq.push({ 0, {0,0} });

	while (!pq.empty())
	{
		coord currCell = pq.top().second;

		int currX = currCell.first;
		int currY = currCell.second;
		int currDir = grid[currX][currY];

		visited[currX * m + currY] = 1;
		pq.pop();

		int weight = 0;

		for (size_t i = 0; i < 4; i++)
		{
			if (isValid(currX + horizontal[i], currY + vertical[i]) && !visited[(currX + horizontal[i]) * m + currY + vertical[i]])
			{
				coord next = { currX + horizontal[i], currY + vertical[i] };

				weight = currDir == (i + 1) ? 0 : 1;

				if (dist[(currX + horizontal[i]) * m + currY + vertical[i]] > dist[currX * m + currY] + weight)
				{
					dist[(currX + horizontal[i]) * m + currY + vertical[i]] = dist[currX * m + currY] + weight;
					pq.push({ dist[(currX + horizontal[i]) * m + currY + vertical[i]] , next });
				}
			}
		}
	}

	cout << dist[n * m - 1];

	return 0;
}
