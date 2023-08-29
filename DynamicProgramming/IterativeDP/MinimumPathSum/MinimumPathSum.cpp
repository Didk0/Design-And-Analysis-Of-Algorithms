#include <iostream>

int main()
{
    // условие: https://leetcode.com/problems/minimum-path-sum/description/
    
    /*int minPathSum(vector<vector<int>>&grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int table[m][n];

        table[0][0] = grid[0][0];
        for (int j = 1; j < n; j++)
        {
            table[0][j] = grid[0][j] + table[0][j - 1];
        }
        for (int i = 1; i < m; i++)
        {
            table[i][0] = grid[i][0] + table[i - 1][0];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                table[i][j] = min(table[i - 1][j], table[i][j - 1]) + grid[i][j];
            }
        }

        return table[m - 1][n - 1];
    }*/

    return 0;
}