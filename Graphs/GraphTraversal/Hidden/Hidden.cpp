#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 50;
const int MOVES_COUNT = 4;
const int SYMBOLS = 27;

int n, m, k;
char table[SIZE][SIZE];
vector<pair<int, int>> symbols[SYMBOLS];

int horizontal[MOVES_COUNT] = { -1, 1, 0, 0 };
int vertical[MOVES_COUNT] = { 0, 0, -1, 1 };

bool isValid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool findWordDFS(int x, int y, char* word)
{
	if (*word == '\0')
		return true;

	for (int i = 0; i < MOVES_COUNT; i++)
	{
		int nextX = x + horizontal[i];
		int nextY = y + vertical[i];

		if (isValid(nextX, nextY) && table[nextX][nextY] == *word)
		{
			if (findWordDFS(nextX, nextY, word + 1))
			{
				return true;
			}
		}
	}

	return false;
}

//bool findWordBFS(int ind, int x, int y, char word[])
//{
//	queue<pair<int, int>> q;
//	q.push({ x, y });
//	int nodesOfLevel = 1;
//
//	while (!q.empty())
//	{
//		pair<int, int> curr = q.front();
//		q.pop();
//		nodesOfLevel--;
//
//		if (word[ind + 1] == '\0')
//			return true;
//
//		for (int i = 0; i < NEXT_COUNT; i++)
//		{
//			int nextX = curr.first + horizontal[i];
//			int nextY = curr.second + vertical[i];
//
//			if (isValid(nextX, nextY) && table[nextX][nextY] == word[ind + 1])
//			{
//				q.push({ nextX, nextY });
//			}
//		}
//
//		if (nodesOfLevel == 0)
//		{
//			nodesOfLevel = q.size();
//			ind++;
//		}
//	}
//
//	return false;
//}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> table[i][j];
			symbols[table[i][j] - 'a'].push_back({ i, j });
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		char word[50];
		cin >> word;
		bool found = false;

		for (size_t j = 0; j < symbols[*word - 'a'].size(); j++)
		{
			if (findWordDFS(symbols[*word - 'a'][j].first, symbols[*word - 'a'][j].second, word + 1))
			{
				found = true;
				break;
			}
		}
		cout << (found ? "Yes\n" : "No\n");
	}

	return 0;
}