#include <iostream>
#include <algorithm>
using namespace std;

long int n, k;
long int flowers[1000005];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> flowers[i];
	}

	sort(flowers, flowers + n, [](int f1, int f2) {
		return f1 > f2;
		});

	long long int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += ((long long)i / k + 1) * flowers[i];
	}

	cout << res;

	return 0;
}