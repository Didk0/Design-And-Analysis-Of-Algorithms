#include <iostream>
#include <queue>
using namespace std;

int n, m, k, startX, startY;
int graph[2001][2001];
int horizontalMoves[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int verticalMoves[] = { 1, -1, 1, -1, 2, 2, -2, -2 };

bool isValid(int x, int y)
{
	return graph[x][y] >= 0 && 0 <= x && x < n && 0 <= y && y < n;
}

int main()
{
	// условие: https://judge.openfmi.net/practice/open_contest?contest_id=178 - рицари

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = -1;
	}

	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
	}

	cin >> startX >> startY;

	queue<pair<int, int>> q;
	q.push({ startX, startY });
	graph[startX][startY] = -1;
	int level = 0, nodesOfLevel = 1, res = 0, count = 0;

	while (!q.empty())
	{
		int currX = q.front().first, currY = q.front().second;
		q.pop();
		nodesOfLevel--;

		for (int i = 0; i < 8; ++i)
		{
			int nextX = currX + horizontalMoves[i], nextY = currY + verticalMoves[i];
			if (isValid(nextX, nextY) && graph[nextX][nextY] != -1)
			{
				if (graph[nextX][nextY] == 1)
				{
					res = level + 1;
					count++;
				}
				else
				{
					q.push({ nextX, nextY });
				}
				graph[nextX][nextY] = -1;
			}
		}

		if (nodesOfLevel == 0)
		{
			nodesOfLevel = q.size();
			level++;
		}
	}

	cout << count << ' ' << res;

	return 0;
}