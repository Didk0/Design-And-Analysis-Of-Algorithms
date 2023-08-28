#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

int n, num;

int main()
{
	priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	priority_queue<int> maxHeap;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (maxHeap.size() == 0 || num < maxHeap.top())
		{
			maxHeap.push(num);
		}
		else
		{
			minHeap.push(num);
		}

		if (maxHeap.size() - 1 > minHeap.size())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (maxHeap.size() + 1 == minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		if (maxHeap.size() == minHeap.size())
		{
			printf("%0.1f ", ((double)maxHeap.top() + minHeap.top()) / 2);
		}
		else if (maxHeap.size() - minHeap.size() == 1)
		{
			printf("%0.1f ", (double)maxHeap.top());
		}
	}

	return 0;
}