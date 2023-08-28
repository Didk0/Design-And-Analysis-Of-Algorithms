//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//double EPS = 0.000000001;
//
//int t;
//int mx1, my1, mx2, my2, v1, v2;
//
//double f(double mid)
//{
//	double fmy1 = my1, fmy2 = my2;
//	return std::sqrt(((double)mx1 - mid) * ((double)mx1 - mid) + fmy1 * fmy1) / v1
//		+ std::sqrt(((double)mx2 - mid) * ((double)mx2 - mid) + fmy2 * fmy2) / v2;
//}
//
//double ternarySearch(double l, double r)
//{
//	while (r - l > EPS) {
//		double m1 = l + (r - l) / 3;
//		double m2 = r - (r - l) / 3;
//		double f1 = f(m1);
//		double f2 = f(m2);
//
//		if (std::abs(f1 - f2) < EPS)
//		{
//			l = m1;
//			r = m2;
//		}
//		else if (f1 < f2)
//		{
//			r = m2;
//		}
//		else
//		{
//			l = m1;
//		}
//	}
//
//	return f(l);
//}
//
//int main()
//{
//	// условие: https://judge.openfmi.net/practice/get_problem_description?contest_id=198&problem_id=589&fbclid=IwAR0FJOtFx7Aa2XLtUb-_eXihWyJ6h__ndgALXIeqvoZSxndu3iayicHTlQ0
//
//	scanf("%d", &t);
//	for (int i = 0; i < t; ++i)
//	{
//		scanf("%d %d %d %d %d %d", &mx1, &my1, &mx2, &my2, &v1, &v2);
//	}
//
//	printf("%.5f", ternarySearch(std::min(mx1, mx2), std::max(mx1, mx2)));
//
//	return 0;
//}

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

double xDrown, yDrown, xPancho, yPancho, vSand, vSea;

double findTime(double x)
{
	double timeOnSand = sqrt((x - xPancho) * (x - xPancho) + yPancho * yPancho) / vSand;
	double timeOnSea = sqrt((x - xDrown) * (x - xDrown) + yDrown * yDrown) / vSea;
	return timeOnSand + timeOnSea;
}

void findMinimum() {
	double left = min(xPancho, xDrown), right = max(xPancho, xDrown), eps = 0.00001, mid1, mid2;

	while (right - left > eps)
	{
		mid1 = left + (right - left) / 3;
		mid2 = right - (right - left) / 3;

		double time1 = findTime(mid1);
		double time2 = findTime(mid2);

		if (time1 < time2)
			right = mid2;
		else
			left = mid1;
	}
	cout << setprecision(5) << fixed << findTime(left) << endl;
}

int main()
{
	//условие: https://judge.openfmi.net/practice/open_contest?contest_id=153

	int query;
	cin >> query;

	for (int i = 0; i < query; i++)
	{
		cin >> xPancho >> yPancho >> xDrown >> yDrown >> vSand >> vSea;
		findMinimum();
	}

	return 0;
}