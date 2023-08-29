#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

long long int n;
long long int distances[6 * 10005];
long long int speeds[6 * 10005];

double calcTime(double x)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		max = std::max(max, (abs(distances[i] - x)) / speeds[i]);
	}
	return max;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> distances[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> speeds[i];
	}

	double left = 0, right = 1000000000, mid1, mid2, eps = 0.0000000001;
	while (right - left > eps)
	{
		mid1 = left + (right - left) / 3;
		mid2 = right - (right - left) / 3;
		double time1 = calcTime(mid1);
		double time2 = calcTime(mid2);

		if (time1 < time2)
			right = mid2;
		else if (time1 > time2)
			left = mid1;
		else if (abs(time1 - time2) < eps)
			break;
	}

	cout << setprecision(10) << fixed << calcTime(left);

	return 0;
}