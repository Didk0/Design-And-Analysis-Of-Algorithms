#include <cstdio>
#include <iostream>
using namespace std;

pair<long long int, long long int> blocs[100005];
int n;

bool OK(long long int parties)
{
	long long int currRakia = 0;
	for (int i = 0; i < n - 1; i++)
	{
		currRakia += blocs[i].second - parties;

		if (currRakia >= 0 && currRakia - (blocs[i + 1].first - blocs[i].first) <= 0)
			currRakia = 0;
		else
			currRakia -= (blocs[i + 1].first - blocs[i].first);
	}
	currRakia += blocs[n - 1].second - parties;

	return currRakia >= 0;
}

int main()
{
	// условие: https://judge.openfmi.net/practice/open_contest?contest_id=37 алкохолици

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%lld %lld", &blocs[i].first, &blocs[i].second);

	long long int left = 1, right = 50, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;

		if (OK(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	printf("%lld", right);

	return 0;
}
