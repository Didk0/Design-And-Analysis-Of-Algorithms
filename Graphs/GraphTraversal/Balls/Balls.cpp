#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

vector<int> graph[100005];
unordered_map<long long int, int> bigToSmall;
bool visited[100005];
long long int n, m, colorsCount = 0;

void dfs(int src)
{
	visited[src] = 1;
	for (int i = 0; i < graph[src].size(); i++)
	{
		if (!visited[graph[src][i]])
			dfs(graph[src][i]);
	}
}

int main()
{
	// условие: https://arena.olimpiici.com/#/catalog/186/problem/100443

	cin >> n >> m;
	long long int ind = 1;

	for (int i = 0; i < m; i++)
	{
		long long int from, to;
		cin >> from >> to;

		if (bigToSmall.find(from) == bigToSmall.end())
			bigToSmall[from] = ind++;
		if (bigToSmall.find(to) == bigToSmall.end())
			bigToSmall[to] = ind++;

		graph[bigToSmall[from]].push_back(bigToSmall[to]);
		graph[bigToSmall[to]].push_back(bigToSmall[from]);
	}

	for (const pair<long long int, int>& p : bigToSmall)
	{
		if (!visited[p.second])
		{
			dfs(p.second);
			colorsCount++;
		}
	}

	cout << n - bigToSmall.size() + colorsCount;

	return 0;
}