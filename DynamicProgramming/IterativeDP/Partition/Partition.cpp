#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long int n;
long long int ways[100001];

int main()
{
	// условие: https://action.informatika.bg/problems/19

	cin >> n;

	ways[3] = ways[4] = ways[5] = 1;
	long long int sum = 0;

	for (long long int i = 6; i <= n; i++)
	{
		sum = (sum + ways[i - 3]) % MOD;
		ways[i] = (ways[i] + sum + 1) % MOD;
	}

	cout << ways[n];

	return 0;
}