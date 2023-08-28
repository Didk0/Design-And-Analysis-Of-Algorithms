#include <iostream>
#include <vector>
using namespace std;

int posOccurs[10002];
int negOccurs[10002];

int main()
{
	vector<int> nums = { 6,2,6,5,1,2 };
	int ind = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= 0)
			posOccurs[nums[i]]++;
		else
			negOccurs[-nums[i]]++;
	}

	for (int i = 10001; i > 0; i--) {
		while (negOccurs[i] > 0) {
			nums[ind++] = -i;
			negOccurs[i]--;
		}
	}

	for (int i = 0; i < 10002; i++) {
		while (posOccurs[i] > 0) {
			nums[ind++] = i;
			posOccurs[i]--;
		}
	}

	int res = 0;
	for (int i = 0; i < nums.size(); i += 2) {
		res += std::min(nums[i], nums[i + 1]);
	}

	return 0;
}