#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//условие: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

	vector<int> arr = { 1,4,2,5,3 };
	int res = 0;

	for (int i = 1; i < arr.size(); i++)
		arr[i] += arr[i - 1];

	for (int i = 1; i <= arr.size(); i += 2) {
		for (int j = 0; j + i <= arr.size(); j++) {
			if (j == 0)
				res += arr[i - 1];
			else
				res += arr[i + j - 1] - arr[j - 1];
		}
	}

	cout << res;
}
