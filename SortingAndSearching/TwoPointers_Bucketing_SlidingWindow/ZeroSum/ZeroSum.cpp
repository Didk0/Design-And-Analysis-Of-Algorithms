#include <iostream>
#include <algorithm>
using namespace std;

int N;
int nums[10004];

int main()
{
	// условие: https://action.informatika.bg/problems/65

	long long int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	std::sort(nums, nums + N);

	for (int i = 0; i < N - 1; i++)
	{
		int left = i + 1;
		int right = N - 1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] == 0)
			{
				// пр. -4 2 2 2 2 2
				if (nums[left] == nums[right])
				{
					int allInRange = right - left + 1;
					count += ((long long)allInRange * ((long long)allInRange - 1LL)) / 2LL; // биномен коефициент allInRange над 2
					break;
				}

				long long int leftCount = 1, rightCount = 1;
				while (left < right && nums[left] == nums[left + 1])
				{
					++leftCount;
					++left;
				}
				while (left < right && nums[right] == nums[right - 1])
				{
					++rightCount;
					--right;
				}

				count += (long long)(leftCount * rightCount); // за всяко от едното множество избираме едно от другото множество
				++left;
				--right;
			}
			else if (nums[i] + nums[left] + nums[right] < 0)
				left++;
			else
				right--;
		}
	}

	printf("%lld", count);

	return 0;
}