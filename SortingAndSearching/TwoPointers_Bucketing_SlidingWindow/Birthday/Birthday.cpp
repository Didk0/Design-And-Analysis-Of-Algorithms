#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
long int s;
pair<long int, int> boxes[100005];

int main()
{
	// условие: https://judge.openfmi.net/practice/open_contest?contest_id=153 рожден ден

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		long int x, y;
		cin >> x >> y;
		boxes[i].first = x + y;
		boxes[i].second = i;
	}

	sort(boxes, boxes + n);

	long int left = 0, right = (long)n - 1, min = INT_MAX, ind1 = -1, ind2 = -1;
	while (left < right)
	{
		if (abs(s - (boxes[left].first + boxes[right].first)) <= min)
		{
			min = abs(s - (boxes[left].first + boxes[right].first));
			ind1 = std::min(boxes[left].second, boxes[right].second);
			ind2 = std::max(boxes[left].second, boxes[right].second);
		}
		if (abs(s - (boxes[left].first + boxes[right - 1].first)) < abs(s - (boxes[left + 1].first + boxes[right].first)))
			right--;
		else
			left++;
	}

	cout << min << endl << ind1 << ' ' << ind2;

	return 0;
}