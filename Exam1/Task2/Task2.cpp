#include <iostream>
using namespace std;

long long int n;
long long int shots[1000005];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> shots[i];
	}

	long long int res = 0, curr = 2, leftInd = 0, rightInd = n - 1, leftSum = shots[leftInd], rightSum = (n > 0 ? shots[rightInd] : 0);
	while (leftInd < rightInd)
	{
		if (leftSum < rightSum)
		{
			leftSum += shots[++leftInd];
			curr++;
		}
		else if (leftSum > rightSum)
		{
			rightSum += shots[--rightInd];
			curr++;
		}
		else
		{
			leftSum += shots[++leftInd];
			rightSum += shots[--rightInd];
			res = curr;
			curr += 2;
		}
	}

	cout << res;

	return 0;
}