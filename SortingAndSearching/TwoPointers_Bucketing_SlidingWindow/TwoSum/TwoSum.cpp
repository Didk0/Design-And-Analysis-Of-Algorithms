#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// втори начин със сортиране
//int main()
//{
//    int n, k;
//    pair<int, int> arr[10000];
//
//    scanf("%d%d", &n, &k);
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%d", &arr[i].first);
//        arr[i].second = i;
//    }
//
//    std::sort(arr, arr + n);
//
//    int left = 0, right = n - 1;
//    while (left <= right)
//    {
//        if (arr[left].first + arr[right].first == k)
//        {
//            printf("%d %d\n", arr[left].second, arr[right].second);
//
//            return 0;
//        }
//
//        if (arr[left].first + arr[right].first < k)
//        {
//            ++left;
//        }
//        else
//        {
//            --right;
//        }
//    }
//
//    printf("Not found");
//
//    return 0;
//}

int main()
{
	// условие: https://leetcode.com/problems/two-sum/description/

	vector<int> nums = { 2,7,11,15 };
	int target = 9;

	unordered_map<int, int> map;
	int ind1 = -1, ind2 = -1;

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (map.find(target - nums[i]) != map.end())
		{
			ind1 = map[target - nums[i]];
			ind2 = i;
		}
		else
			map.insert({ nums[i],i });
	}

	cout << ind1 << " " << ind2;

	return 0;
}