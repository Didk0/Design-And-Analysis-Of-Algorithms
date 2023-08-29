#include <iostream>
#include <algorithm>
using namespace std;

long long int n, k;
long long int s;
long long int packages[100005];

bool OK(long long int seconds)
{
	long long int maxPopcorns = seconds * s, currMembers = k, currPopcorns = 0;
	for (int i = 0; i < n; i++)
	{
		if (currPopcorns + packages[i] <= maxPopcorns)
		{
			currPopcorns += packages[i];
		}
		else
		{
			currPopcorns = 0;
			currMembers--;
			i--;
		}
		if (currMembers <= 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> packages[i];
	}

	long long int left = 0, right = 1000000000, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (OK(mid))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << left;

	return 0;
}