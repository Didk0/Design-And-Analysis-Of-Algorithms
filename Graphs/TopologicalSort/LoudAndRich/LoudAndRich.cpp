#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// условие: https://leetcode.com/problems/loud-and-rich/description/

	vector<vector<int>> richer = { {1, 0} ,{2, 1},{3, 1},{3, 7},{4, 3},{5, 3},{6, 3} };
	vector<int> quiet = { 3,2,5,4,6,1,7,0 };

	vector<int> graph[500];
	int inDegrees[500] = { 0, };
	vector<int> topSort;
	vector<int> answer(quiet.size());

	for (int i = 0; i < richer.size(); i++)
	{
		graph[richer[i][0]].push_back(richer[i][1]);
		inDegrees[richer[i][1]]++;
	}

	for (int i = 0; i < quiet.size(); i++)
	{
		answer[i] = i;
		if (inDegrees[i] == 0)
			topSort.push_back(i);
	}

	for (int i = 0; i < topSort.size(); i++)
	{
		int curr = topSort[i];

		for (int j = 0; j < graph[curr].size(); j++)
		{
			if (quiet[curr] < quiet[graph[curr][j]])
			{
				quiet[graph[curr][j]] = quiet[curr];
				answer[graph[curr][j]] = answer[curr];
			}

			inDegrees[graph[curr][j]]--;

			if (inDegrees[graph[curr][j]] == 0)
				topSort.push_back(graph[curr][j]);
		}
	}

	for (size_t i = 0; i < quiet.size(); i++)
	{
		cout << answer[i] << ' ';
	}
}
