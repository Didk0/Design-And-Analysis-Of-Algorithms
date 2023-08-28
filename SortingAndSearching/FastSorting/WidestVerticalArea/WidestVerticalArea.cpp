#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // условие: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

    vector<vector<int>> points = { {3, 1}, {9, 0},{1, 0},{1, 4}, {5, 3}, { 8, 8 } };

    std::sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2)->bool {
        return p1[0] < p2[0];
        });

    int maxWidth = 0;

    for (size_t i = 0; i < points.size() - 1; i++)
    {
        maxWidth = std::max(maxWidth, points[i + 1][0] - points[i][0]);
    }

    cout << maxWidth;

    return 0;
}