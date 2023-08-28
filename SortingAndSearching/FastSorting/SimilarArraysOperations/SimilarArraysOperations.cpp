#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 8,12,6 };
	vector<int> target = { 2,14,10 };

	std::sort(nums.begin(), nums.end(), [](int x, int y) {
		if (x % 2 == y % 2)
			return x < y;

		return x % 2 == 1 && y % 2 == 0;
		});

	std::sort(target.begin(), target.end(), [](int x, int y) {
		if (x % 2 == y % 2)
			return x < y;

		return x % 2 == 1 && y % 2 == 0;
		});

	long long operations = 0;

	for (size_t i = 0; i < nums.size(); i++)
		operations += abs(nums[i] - target[i]) / 2;

	cout << operations / 2;

	return 0;
}