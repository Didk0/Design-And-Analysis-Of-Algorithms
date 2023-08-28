#include <iostream>
#include <algorithm>
using namespace std;

std::pair<int, int> events[1000002];

int main()
{
	//условие: https://judge.openfmi.net/practice/get_problem_description?contest_id=175&problem_id=543

	int eventsCount = 0;

	while (cin >> events[eventsCount].first >> events[eventsCount].second)
	{
		eventsCount++;
	}

	if (eventsCount == 0)
	{
		cout << 0;
		return 0;
	}

	std::sort(events, events + eventsCount, [](pair<int, int>& event1, pair<int, int>& event2)
		{
			return event1.first + event1.second < event2.first + event2.second;
		});

	int count = 1;
	int curr = events[0].first, next = curr + events[0].second;

	for (int i = 0; i < eventsCount - 1; i++)
	{
		while (i < eventsCount - 1 && events[i + 1].first < next)
			i++;

		if (events[i + 1].first >= next)
		{
			count++;
			curr = events[i + 1].first;
			next = curr + events[i + 1].second;
		}
	}
	if (next <= events[eventsCount - 1].first)
		count++;

	cout << count;

	return 0;
}