#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n;
string start, dest;
string key, value;

unordered_map<string, string> forwards;
unordered_map<string, string> backwards;
unordered_map<string, string> output;

int main()
{
	cin >> n >> start >> dest;
	for (int i = 0; i < n - 1; i++)
	{
		string from, to;
		cin >> from >> to;

		if (from == start)
		{
			forwards[from] = to;
			output[from] = to;
			continue;
		}
		else if (to == start)
		{
			forwards[to] = from;
			output[to] = from;
			continue;
		}

		if (from == dest)
		{
			backwards[from] = to;
			output[to] = from;
			continue;
		}
		else if (to == dest)
		{
			backwards[to] = from;
			output[from] = to;
			continue;
		}


		if (forwards.find(from) == forwards.end())
			forwards[from] = to;
		else if (backwards.find(from) == backwards.end())
			backwards[from] = to;

		if (backwards.find(to) == backwards.end())
			backwards[to] = from;
		else if (forwards.find(to) == forwards.end())
			forwards[to] = from;
	}

	string curr = start;
	while (forwards.find(curr) != forwards.end())
	{
		string next = forwards[curr];

		if (forwards.find(next) != forwards.end())
		{
			output[next] = forwards[next];
		}
		else if (backwards.find(next) != backwards.end() && backwards[next] != curr)
		{
			output[next] = backwards[next];
		}
		curr = next;
	}
	key = curr;

	string curr = dest;
	while (backwards.find(curr) != backwards.end() || forwards.find(curr) != forwards.end())
	{
		string next = backwards[curr];

		if (backwards.find(next) != backwards.end())
		{
			output[backwards[next]] = next;
		}
		else if (forwards.find(next) != forwards.end() && forwards[next] != curr)
		{
			output[forwards[next]] = next;
		}
		curr = next;
	}
	key = curr;

	return 0;
}