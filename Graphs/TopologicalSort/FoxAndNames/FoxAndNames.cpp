#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int LETTERS_COUNT = 256;

vector<char> topSort;
char words[101][101];
vector<char> graph[LETTERS_COUNT];
char inDegree[LETTERS_COUNT];
int n;
//char words[101][101];
//vector<char> graph[256];
//bool visited[256];
//bool onPath[256];
//vector<char> s;

//bool topSort(char u)
//{
//	if (onPath[u])
//	{
//		return true;
//	}
//
//	onPath[u] = true;
//
//	for (char v : graph[u])
//	{
//		if (!visited[v] && topSort(v))
//		{
//			return true;
//		}
//	}
//
//	onPath[u] = false;
//	visited[u] = true;
//
//	s.push_back(u);
//
//	return false;
//}

int main()
{
	// условие: https://codeforces.com/contest/510/problem/C

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		words[i];
		words[i + 1];

		bool prefix = 0;
		int ind = 0;
		while (words[i][ind] != '\0' && words[i][ind] == words[i + 1][ind])
		{
			ind++;
		}

		if (words[i][ind] != '\0' && words[i + 1][ind] == '\0')
		{
			cout << "Impossible";
			return 1;
		}

		if (words[i][ind] != '\0')
		{
			graph[words[i][ind]].push_back(words[i + 1][ind]);
			inDegree[words[i + 1][ind]]++;
		}
	}

	for (char i = 'a'; i <= 'z'; i++)
	{
		if (inDegree[i] == 0)
			topSort.push_back(i);
	}

	for (size_t i = 0; i < topSort.size(); i++)
	{
		char curr = topSort[i];
		for (size_t j = 0; j < graph[curr].size(); j++)
		{
			inDegree[graph[curr][j]]--;
			if (inDegree[graph[curr][j]] == 0)
				topSort.push_back(graph[curr][j]);
		}
	}

	if (topSort.size() != 26)
	{
		cout << "Impossible";
		return 2;
	}

	for (char i : topSort)
		cout << i;

	/*for (int i = 0; i < n; i++)
	{
		cin >> words[i];
	}

	for (int i = 1; i < n; i++)
	{
		int ind = 0;
		while (words[i-1][ind] != '\0' && words[i-1][ind] == words[i][ind])
		{
			ind++;
		}

		if (words[i-1][ind] != '\0' && words[i][ind] == '\0')
		{
			cout << "Impossible";
			return 1;
		}
		if (words[i-1][ind] != '\0')
		{
			graph[words[i-1][ind]].push_back(words[i][ind]);
		}
	}

	for (char c = 'a'; c <= 'z'; c++)
	{
		if (!visited[c] && topSort(c))
		{
			cout << "Impossible";
			return 2;
		}
	}

	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it;
	}*/

	return 0;
}