#include <cstdio>
#include <algorithm>
#include <climits>

int n, m;
long long int nums[100420];

// Kadane's algorithm
bool possible(long long int k)
{
	long long int maxSum = INT_MIN, currSum = 0;

	for (long long int i = 0; i < (long long)n; ++i)
	{
		currSum += nums[i] + (i + 1) * k;

		if (maxSum < currSum)
			maxSum = currSum;

		if (currSum < 0)
			currSum = 0;
		/* може и следната имплементация:
		currSum = std::max(nums[i] + (i + 1) * k, currSum + nums[i] + (i + 1) * k);
		maxSum = std::max(maxSum, currSum);*/
	}

	return maxSum >= m;
}

int main()
{
	// условие: https://action.informatika.bg/problems/168

	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%lld", &nums[i]);
	}

	int left = -1002000000, right = 1002000000, res;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (possible(mid))
		{
			right = mid - 1;
			res = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	printf("%d", res);

	return 0;
}