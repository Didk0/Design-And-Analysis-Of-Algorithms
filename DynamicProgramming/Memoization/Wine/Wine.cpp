#include <iostream>
using namespace std;

long long int n;
long long int wine[1003];
long long int dp[1003][1003];

long long int solve(long long int lm, long long int rm, long long int year)
{
	if (lm > rm)
	{
		return 0;
	}
	if (dp[lm][rm] > 0)
	{
		return dp[lm][rm];
	}

	long long int res = 0;
	res = solve(lm + 1, rm, year + 1) + year * wine[lm];
	res = max(res, solve(lm, rm - 1, year + 1) + year * wine[rm]);
	return dp[lm][rm] = res;
}

int main()
{
	// условие: https://action.informatika.bg/problems/243

    cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> wine[i];
	}

	cout << (solve(0, n - 1, 1));

    return 0;
}
