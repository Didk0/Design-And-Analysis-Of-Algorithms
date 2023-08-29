#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	long long int from;
	long long int to;
	long long int degrees;
};

long long int n, m, a, b, c;
vector<long long int> graph[1005];
vector<long long int> topSort;
long long int inDegree[1005];
Edge edges[10005];

void init()
{
	topSort.clear();
	fill(inDegree, inDegree + n + 1, 0);
	for (long long int i = 1; i <= n; i++)
		graph[i].clear();
}

bool validTopSort(long long int maxDegrees)
{
	init();

	for (long long int i = 0; i < m; i++)
	{
		if (maxDegrees >= edges[i].degrees)
		{
			graph[edges[i].to].push_back(edges[i].from);
			inDegree[edges[i].from]++;
		}
	}

	for (long long int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
			topSort.push_back(i);
	}

	for (size_t i = 0; i < topSort.size(); i++)
	{
		long long int curr = topSort[i];
		for (long long int neighbour : graph[curr])
		{
			inDegree[neighbour]--;
			if (inDegree[neighbour] == 0)
				topSort.push_back(neighbour);
		}
	}

	return topSort.size() == (size_t)n;
}

int main()
{
	cin >> n >> m;

	for (long long int i = 0; i < m; i++)
		cin >> edges[i].from >> edges[i].to >> edges[i].degrees;

	vector<long long int> result;
	
	long long int left = 0, right = 100000, res = 0;

	while (left <= right)
	{
		long long int mid = left + (right - left) / 2;

		if (validTopSort(mid))
		{
			res = mid;
			result = topSort;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << (left == 100000 + 1 ? -1 : res) << endl;
	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << ' ';

	return 0;
}
