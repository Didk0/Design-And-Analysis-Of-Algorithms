#include <iostream>
#include <climits>
using namespace std;

long long int n, f;

long long int sum(long long int m)
{
	return (m + f) * (m + f - 1) / 2 - (f - 1) * f / 2;
}

int main()
{
	// условие: https://action.informatika.bg/problems/117

	cin >> n >> f;

	long long int left = 0, right = INT_MAX - f, ans = -1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (sum(mid) < n)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}

	cout << ans;
}
