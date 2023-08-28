#include <iostream>
#include <algorithm>
using namespace std;

int socksCount, maxPairs;
int socks[100004];

int main()
{
	// https://action.informatika.bg/problems/226

	cin >> socksCount >> maxPairs;
	for (int i = 0; i < socksCount; i++)
	{
		cin >> socks[i];
	}

	sort(socks, socks + socksCount);
	
	long long int left = 0, right = 1000000000, mid, res;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		int pairs = 0;
		for (int i = 0; i < socksCount - 1; i++)
		{
			if ((long long)socks[i + 1] - socks[i] <= mid)
			{
				pairs++;
				i++;
			}
		}
		if (pairs < maxPairs)
		{
			left = mid + 1;
		}
		else
		{
			res = mid;
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}
