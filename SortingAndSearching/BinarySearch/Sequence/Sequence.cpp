#include <iostream>
#include <climits>
using namespace std;

unsigned int n, k;
int nums[1000004];

bool checkSequence(int L)
{
	int curr = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] >= L)
		{
			curr++;
			if (curr == k)
				return true;
		}
		else
			curr = 0;
	}
	return false;
}

int main()
{
	// условие: https://judge.openfmi.net/practice/open_contest?contest_id=85

	cin >> n >> k;
	for (unsigned int i = 0; i < n; i++)
		cin >> nums[i];

	int left = 0, right = 2000000, mid, res = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (checkSequence(mid))
		{
			res = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}
