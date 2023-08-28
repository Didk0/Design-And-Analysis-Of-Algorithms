#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	// условие: https://leetcode.com/problems/sliding-window-maximum/

	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	size_t k = 3;

	vector<int> res;
	res.resize(nums.size() - k + 1);
	deque<int> dq;
	size_t ind = 0;

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (!dq.empty() && dq.front() + k <= i)
		{
			dq.pop_front();
		}

		while (!dq.empty() && nums[i] > nums[dq.back()])
		{
			dq.pop_back();
		}
		dq.push_back(i);
		if (i >= k - 1)
			res[ind++] = nums[dq.front()];
	}

	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}

	return 0;
}