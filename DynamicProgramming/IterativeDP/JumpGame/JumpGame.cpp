#include <iostream>
#include <vector>
using namespace std;

bool ways[10000];

int main()
{
    // условие: https://leetcode.com/problems/jump-game/description/

    vector<int> nums = { 2,3,1,1,4 };

    ways[0] = true;

    for (int i = 1; i < nums.size(); i++)
    {
        int dist = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            dist++;
            if (ways[j] && nums[j] >= dist)
            {
                ways[i] = true;
                break;
            }
        }
    }

    cout << ways[nums.size() - 1];

    return 0;
}
