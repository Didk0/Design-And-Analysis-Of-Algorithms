#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> graph[1005];
bool used[1005];
queue<int> wave;
int n, m;
int components[1005];
int componentsCount = 0;

void bfs(int source)
{
	wave.push(source);
	while (!wave.empty())
	{
		int curr = wave.front();
		components[curr] = componentsCount;
		used[curr] = 1;
		wave.pop();
		for (size_t i = 0; i < graph[curr].size(); i++)
		{
			if (!used[graph[curr][i]])
			{
				wave.push(graph[curr][i]);
			}
		}
	}
}


int main()
{
	// условие: https://arena.olimpiici.com/#/catalog/175/problem/100415

	cin >> n >> m;
	int from, to;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			bfs(i);
			componentsCount++;
		}
	}

	string str;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> from >> to;
		if (components[from] == components[to])
			str.push_back('1');
		else
			str.push_back('0');
	}

	cout << str;

	return 0;
}
