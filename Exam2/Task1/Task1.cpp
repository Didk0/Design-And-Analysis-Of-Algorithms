#include <iostream>
#include <queue>
using namespace std;

const char VIS = '#';

long long int n, m, k;
char graph[601][601];
long long int dist[601 * 601];

long long int horizontal[4] = { -1, 1, 0, 0 };
long long int vertical[4] = { 0, 0, -1, 1 };

bool isValid(long long int x, long long int y)
{
	return 0 <= x && x < n && 0 <= y && y < m&& graph[x][y] != '#';
}

int main()
{
	cin >> n >> m >> k;

	for (long long int i = 0; i < n; i++)
		cin >> graph[i];

	queue<pair<long long int, long long int>> q;
	long long int sum = 0;

	for (int i = 0; i < k; i++)
	{
		long long int x, y;
		cin >> x >> y;
		graph[x - 1][y - 1] = VIS;
		q.push({ x - 1,y - 1 });
		dist[(x - 1) * m + y - 1] = 0;
	}

	while (!q.empty())
	{
		pair<long long int, long long int> currCell = q.front();
		q.pop();
		long long int currX = currCell.first;
		long long int currY = currCell.second;
		graph[currX][currY] = VIS;

		for (long long int i = 0; i < 4; i++)
		{
			long long int nextX = currX + horizontal[i];
			long long int nextY = currY + vertical[i];

			if (isValid(nextX, nextY))
			{
				q.push({ nextX, nextY });
				dist[nextX * m + nextY] = dist[currX * m + currY] + 1;
				sum += dist[nextX * m + nextY];
				graph[nextX][nextY] = VIS;
			}
		}
	}

	cout << sum;

	return 0;
}
