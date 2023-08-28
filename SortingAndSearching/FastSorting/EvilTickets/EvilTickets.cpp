#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

std::pair<int, int> labels[1000002];

int main()
{
	// условие: https://judge.openfmi.net/practice/get_problem_description?contest_id=175&problem_id=544

	int numbersCount, labelsCount;
	scanf("%d%d", &numbersCount, &labelsCount);

	for (int i = 0; i < labelsCount; i++)
	{
		scanf("%d%d", &labels[i].first, &labels[i].second);
	}

	std::sort(labels, labels + labelsCount, [](pair<int, int>& label1, pair<int, int>& label2)
		{
			return label1.first == label2.first ? label1.second < label2.second : label1.first < label2.first;
		});

	int count = 0;
	int start = labels[0].first;
	int end = labels[0].second;

	for (int i = 1; i < labelsCount; i++)
	{
		if (labels[i].first <= end)
		{
			end = std::max(end, labels[i].second);
		}
		else 
		{
			count += end - start + 1;
			start = labels[i].first;
			end = labels[i].second;
		}
	}
	count += end - start + 1;

	printf("%d", count);

	return 0;
}

// II начин:
//struct Point
//{
//    int val;
//    bool start;
//
//    bool operator <(const Point& other)
//    {
//        return val < other.val || (val == other.val && start);
//    }
//};
//int n, m;
//Point arr[2000420];
//
//int main()
//{
//    int from, to;
//    scanf("%d%d", &n, &m);
//    for (int i = 0; i < m; ++i)
//    {
//        scanf("%d%d", &from, &to);
//        arr[i] = { from, true };
//        arr[m + i] = { to, false };
//    }
//    std::sort(arr, arr + 2 * m);
//
//    int starts = 0, ends = 0, res = 0, start;
//    for (int i = 0; i < 2 * m; ++i)
//    {
//        if (arr[i].start)
//        {
//            if (starts == ends)
//            {
//                start = arr[i].val;
//            }
//            ++starts;
//        }
//        else
//        {
//            ++ends;
//        }
//
//        if (starts == ends)
//        {
//            res += (arr[i].val - start + 1);
//        }
//    }
//
//    printf("%d", res);
//
//    return 0;
//}