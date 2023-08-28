#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	// условие: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/description/

	vector<std::pair<int, int>> times = { {1,2}, {2,1}, {3,2}, {2,1} };
	//vector<std::pair<int, int>> times = { {1,2}, {4,3}, {3,1} };

	std::sort(times.begin(), times.end(), [](pair<int, int>& t1, pair<int, int>& t2)
		{
			return t1.second > t2.second;
		});

	int daysPassed = times[0].first;
	int total = times[0].first + times[0].second;

	for (size_t i = 1; i < times.size(); i++)
	{
		daysPassed += times[i].first;
		total = std::max(total, daysPassed + times[i].second);
	}

	cout << total;

	return 0;
}