#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<size_t, size_t> rectangles[10002];
pair<size_t, size_t> dots[100003];

int main()
{
	// условие: http://www.math.bas.bg/infos/EK_2018_NOI_1/u/B.pdf

	size_t rectCount, dotsCount;
	cin >> rectCount >> dotsCount;

	for (size_t i = 0; i < rectCount; i++)
		cin >> rectangles[i].first >> rectangles[i].second;

	for (size_t i = 0; i < dotsCount; i++)
		cin >> dots[i].first >> dots[i].second;

	std::sort(dots, dots + dotsCount, [](pair<size_t, size_t>& d1, pair<size_t, size_t>& d2) {
		return d1.first < d2.first || d1.first == d2.first && d1.second < d2.second;
		});

	size_t currX = rectCount == 0 ? 0 : rectangles[0].first;
	size_t dotInd = 0, count = 0;
	size_t rectInd = 0;

	while (rectInd < rectCount)
	{
		if (dotInd >= dotsCount)
			break;

		if (dots[dotInd].first <= currX && dots[dotInd].second <= rectangles[rectInd].second)
		{
			count++;
			dotInd++;
		}
		else
		{
			if (dotInd < dotsCount - 1 && dots[dotInd + 1].first <= currX && dots[dotInd + 1].second <= rectangles[rectInd].second)
				dotInd++;
			else 
				currX += rectangles[++rectInd].first;
		}
	}

	cout << count;

	return 0;
}