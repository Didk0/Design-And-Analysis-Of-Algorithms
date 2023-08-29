#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// условие: https://action.informatika.bg/problems/113

	int n;
	cin >> n;

	vector<int> nums(n);
	vector<pair<int, int>> lens = { {0,0} }; // first is for positive, second is for negative

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int diff = nums[i] - nums[i + 1];
		if (diff > 0)
			lens.push_back({ lens[i].second + 1, lens[i].second });
		else if (diff < 0)
			lens.push_back({ lens[i].first, lens[i].first + 1 });
		else
			lens.push_back({ lens[i].first, lens[i].second });
	}

	cout << max(lens[n - 1].first, lens[n - 1].second) + 1;

	return 0;
}