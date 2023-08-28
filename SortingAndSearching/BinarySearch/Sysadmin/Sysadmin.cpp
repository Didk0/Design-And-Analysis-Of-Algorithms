#include <iostream>
using namespace std;

int parts[100002];

int main()
{
	// условие: https://action.informatika.bg/problems/130

	int n;
	long long int k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> parts[i];
	}

	long long int left = 1, right = 1000000000, res = 0;
	while (left <= right)
	{
		long long int mid = left + (right - left) / 2;
		long long int count = 0;
		for (int i = 0; i < n; i++)
		{
			count += parts[i] / mid;
		}
		if (count < k)
		{
			right = mid - 1;
		}
		else if (count >= k)
		{
			left = mid + 1;
			res = mid;
		}
	}

	cout << res;

	return 0;
}
