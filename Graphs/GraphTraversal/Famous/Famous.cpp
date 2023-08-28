#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

const int MAX = 1005;
int n, m, f, k;

vector<int> graph[MAX];
int calls[MAX]; // number of messages for every person (+k if he/she is famous from the start)

queue<int> q;
unordered_map<string, int> nameToNum; // name -> index
string numToName[MAX]; // index -> name

int main()
{
	// условие: https://action.informatika.bg/problems/147

	cin >> n >> k >> f >> m;
	int ind = 0;

	for (int i = 0; i < f; i++)
	{
		string n;
		cin >> n;

		q.push(ind);
		calls[ind] = k;
		nameToNum[n] = ind;
		numToName[ind++] = n;
	}

	set<pair<string, string>> messagesSet;
	for (int i = 0; i < m; i++)
	{
		string n1, n2;
		cin >> n1 >> n2;

		if (messagesSet.find({ n1, n2 }) != messagesSet.end()
			|| messagesSet.find({ n2, n1 }) != messagesSet.end())
			continue;

		messagesSet.insert({ n1, n2 });
		messagesSet.insert({ n2, n1 });

		if (nameToNum.find(n1) == nameToNum.end())
		{
			nameToNum[n1] = ind;
			numToName[ind++] = n1;
		}
		if (nameToNum.find(n2) == nameToNum.end())
		{
			nameToNum[n2] = ind;
			numToName[ind++] = n2;
		}

		graph[nameToNum[n1]].push_back(nameToNum[n2]);
		graph[nameToNum[n2]].push_back(nameToNum[n1]);
	}

	vector<string> result;
	while (!q.empty())
	{
		int curr = q.front();
		result.push_back(numToName[curr]);
		q.pop();

		for (size_t i = 0; i < graph[curr].size(); i++)
		{
			calls[graph[curr][i]]++;

			if (calls[graph[curr][i]] == k)
				q.push(graph[curr][i]);
		}
	}

	sort(result.begin(), result.end());

	for (size_t i = 0; i < result.size(); i++)
		cout << result[i] << ' ';

	return 0;
}
