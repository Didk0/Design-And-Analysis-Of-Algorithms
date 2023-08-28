//Втори начин:
//#include <cstdio>
//#include <climits>
//#include <algorithm>
//
//long long int daysCount, baloonsCount;
//int baloons[100001];
//int candies[100001];
//
//bool good(long long int candyGuess)
//{
//    long long int neededBalloons = 0;
//    for (int i = 0; i < daysCount; ++i)
//    {
//        neededBalloons += std::max((long long)0, (long long)baloons[i] - candyGuess / (long long)candies[i]);
//    }
//
//    return neededBalloons <= baloonsCount;
//}
//
//int main()
//{
//    scanf_s("%lld %lld", &daysCount, &baloonsCount);
//    for (int i = 0; i < daysCount; ++i)
//    {
//        scanf_s("%d", &baloons[i]);
//    }
//    for (int i = 0; i < daysCount; ++i)
//    {
//        scanf_s("%d", &candies[i]);
//    }
//
//    long long int left = 0, right = LONG_MAX;
//    while (left <= right)
//    {
//        long long mid = left + (right - left) / 2;
//        if (good(mid))
//        {
//            right = mid - 1;
//        }
//        else
//        {
//            left = mid + 1;
//        }
//    }
//
//    printf("%lld", left);
//
//    return 0;
//}

#include <cstdio>
#include <algorithm>
#include <climits>

int daysCount;
long long int baloonsCount;
long long int baloons[100005];
long long int candies[100005];

int main()
{
    // условие: https://judge.openfmi.net/practice/open_contest?contest_id=176 - балони и бонбони

    scanf_s("%d%lld", &daysCount, &baloonsCount);
    for (int i = 0; i < daysCount; i++)
        scanf_s("%lld", &baloons[i]);
    for (int i = 0; i < daysCount; i++)
        scanf_s("%lld", &candies[i]);

    long long int left = 0, right = LONG_MAX, mid, res = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        long long int currBaloons = baloonsCount;
        bool enough = true;

        for (int i = 0; i < daysCount; i++)
        {
            long long int currCandies = baloons[i] * candies[i];

            if (currCandies > mid)
            {
                long long int baloonsToRemove = std::min(currBaloons, currCandies / candies[i] - mid / candies[i]);
                currBaloons -= baloonsToRemove;
                currCandies -= candies[i] * baloonsToRemove;
            }

            if (currCandies > mid && currBaloons == 0)
            {
                enough = false;
                break;
            }
        }

        if (enough)
        {
            res = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    printf("%lld", res);

    return 0;
}