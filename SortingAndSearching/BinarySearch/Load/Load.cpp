#include <cstdio>
using namespace std;

int n, k;
long long int stations[100005];

int main()
{
	// условие: https://action.informatika.bg/problems/141

	scanf_s("%d%d", &n, &k);
	scanf_s("%lld", &stations[n + 1]);
	for (int i = 1; i <= n; i++)
		scanf_s("%lld", &stations[i]);

	long long int left = 0, right = stations[n + 1], res = 0;
	while (left <= right)
	{
		int refills = 0;
		long long int mid = left + (right - left) / 2;
		long long int dist = 0, currFuel = mid;
		for (int i = 0; i < n + 1; i++)
		{
			dist = stations[i + 1] - stations[i];
			if (currFuel < dist)
			{
				currFuel = mid;
				refills++;
			}
			currFuel -= dist;
			if (mid < dist || refills > k)
			{
				refills = k + 1;
				break;
			}
		}
		if (refills > k)
			left = mid + 1;
		else
		{
			right = mid - 1;
			res = mid;
		}
	}

	printf("%lld", res);

	return 0;
}