#include <iostream>
#include <deque>
using namespace std;

int n, k;
long long int FIRST, MUL, ADD, MOD;

int main()
{
	// условие: https://action.informatika.bg/problems/105

	cin >> n >> k >> FIRST >> MUL >> ADD >> MOD;
	deque<pair<long long int, long long int>> dq;

	long long int currDay = 1, res = FIRST;
	dq.push_back({ FIRST,0 });

	for (; currDay < n; ++currDay)
	{
		FIRST = (FIRST * MUL + ADD) % MOD;

		if (currDay >= k && !dq.empty() && dq.front().second == currDay - k)
		{
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().first <= FIRST)
		{
			dq.pop_back();
		}

		dq.push_back({ FIRST, currDay });
		res += dq.front().first;
	}

	cout << res;

	return 0;
}