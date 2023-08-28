#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

bool visited[10000];
vector<int> graph[10000];

unordered_map<string, string> SonToParent;

unordered_map<string, int> nameToNum;
string numToName[10000];

void dfsFindMaxPath(int start, vector<int>& currPath, vector<int>& maxPath, vector<int>& globalMaxPath)
{
	visited[start] = 1;
	currPath.push_back(start);

	for (int neighbour : graph[start])
	{
		dfsFindMaxPath(neighbour, currPath, maxPath, globalMaxPath);
	}

	if (currPath.size() > maxPath.size())
	{
		maxPath = currPath;
		if (maxPath.size() > globalMaxPath.size())
		{
			globalMaxPath = maxPath;
		}
		else if (maxPath.size() == globalMaxPath.size()
			&& strcmp(numToName[maxPath.front()].c_str(), numToName[globalMaxPath.front()].c_str()) > 0)
		{
			globalMaxPath = maxPath;
		}
	}

	currPath.pop_back();
}

int main()
{
	// условие: https://arena.olimpiici.com/#/catalog/169/problem/100400

	int relations;
	cin >> relations;

	string wrong;
	bool found = false;
	int ind = 0;

	for (int i = 0; i < relations; i++)
	{
		string r1, r2;
		cin >> r1 >> r2;

		if (nameToNum.find(r1) == nameToNum.end())
		{
			nameToNum[r1] = ind;
			numToName[ind++] = r1;
		}
		if (nameToNum.find(r2) == nameToNum.end())
		{
			nameToNum[r2] = ind;
			numToName[ind++] = r2;
		}

		if (SonToParent.find(r2) == SonToParent.end())
			graph[nameToNum[r1]].push_back(nameToNum[r2]);

		if (SonToParent.find(r2) != SonToParent.end() && strcmp(SonToParent[r2].c_str(), r1.c_str()) != 0)
		{
			found = true;
			wrong = r2;
		}
		SonToParent[r2] = r1;
	}

	if (found)
	{
		cout << wrong;
		return 0;
	}

	vector<int> globalMaxPath, currPath, currMaxPath;
	for (int i=0; i<ind; i++)
	{
		currMaxPath.clear();
		if (visited[i])
			continue;

		dfsFindMaxPath(i, currPath, currMaxPath, globalMaxPath);
	}
	cout << numToName[globalMaxPath.front()];

	return 0;
}