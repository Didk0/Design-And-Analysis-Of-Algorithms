#include <cstdio>
#include <algorithm>
using namespace std;

int multiSet[1000005];

int main()
{
	// условие: https://judge.openfmi.net/practice/open_contest?contest_id=37

	int N, M;
	scanf_s("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf_s("%d", &multiSet[i]);

	sort(multiSet, multiSet + N);

	for (int i = 0; i < M; i++)
	{
		int sum;
		scanf_s("%d", &sum);

		int left = 0, right = N - 1;
		bool found = false;
		while (left < right)
		{
			if (multiSet[left] + multiSet[right] == sum)
			{
				found = true;
				break;
			}
			else if (multiSet[left] + multiSet[right] < sum)
			{
				left++;
			}
			else
				right--;
		}
		if (found)
			printf("YES");
		else
			printf("NO");
		if (i < M - 1)
			printf("\n");
	}

	return 0;
}