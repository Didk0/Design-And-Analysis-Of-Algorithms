#include <iostream>
using namespace std;

int main()
{
	// условие: https://leetcode.com/problems/unique-paths/description/

	const int m = 3, n = 7;

	int paths[m][n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				paths[i][j] = 1;
			}
			else if (j == 0)
			{
				paths[i][j] = 1;
			}
			else
				paths[i][j] = 0;
		}
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			paths[i][j] += paths[i][j - 1];
			paths[i][j] += paths[i - 1][j];
		}
	}

	return 0;
}
