#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> rooms = { {1,3}, {3,0,1}, {2}, {0} };
bool visited[1005];
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < rooms[curr].size(); i++)
		{
			if (!visited[rooms[curr][i]])
			{
				q.push(rooms[curr][i]);
				visited[rooms[curr][i]] = true;
			}
		}
	}
}

int main()
{
	// условие: https://leetcode.com/problems/keys-and-rooms/

	bfs(0);
	int count = 0;
	for (int i = 0; i < rooms.size(); i++)
	{
		if (visited[i])
			count++;
	}
	cout << (count == rooms.size());

	return 0;
}
