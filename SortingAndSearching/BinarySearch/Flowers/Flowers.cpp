#include <iostream>
#include <algorithm>
using namespace std;

long long int N, L, D, first, A, B;
long long int arr[100420];

void genFirstK(int k)
{
	arr[0] = 0;
	arr[1] = first;
	for (int i = 2; i <= k; ++i)
	{
		arr[i] = (arr[i - 1] * A + B) % (L + 1LL);
	}
	arr[k + 1] = L;
}

int maxDist(int k)
{
	long long int dist = -1;
	for (int i = 1; i < k; ++i)
	{
		dist = std::max(dist, arr[i] - arr[i - 1]);
	}

	return dist;
}

int main()
{
	// https://judge.openfmi.net/practice/open_contest?contest_id=183

	cin >> N >> L >> D >> first >> A >> B;

	int left = 1, right = N, res = -1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		genFirstK(mid);
		std::sort(arr, arr + mid + 2);
		if (maxDist(mid + 2) <= D)
		{
			right = mid - 1;
			res = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << res;

	return 0;
}