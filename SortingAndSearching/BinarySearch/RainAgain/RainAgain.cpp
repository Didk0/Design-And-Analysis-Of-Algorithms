#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_NUM 1000000007
#define MIN_NUM -1000000007

int n, D, next, first, A, B, potLength;

struct Bucket
{
    int start;
    int end;

    Bucket()
        : start(MAX_NUM), end(MIN_NUM) {}

    void expand(int newBorder)
    {
        start = std::min(start, newBorder);
        end = std::max(end, newBorder);
    }
};

Bucket buckets[11000000];

int main()
{
    // условие: https://action.informatika.bg/problems/68

    cin >> n >> potLength >> D >> first >> A >> B;

    int bucketsCount = (potLength + 1) / D + ((potLength + 1) % D > 0);

    if (bucketsCount - 2 > n)
    {
        cout << "-1";
        return 0;
    }

    buckets[0].end = 0;
    buckets[bucketsCount - 1].start = potLength;

    int remaining = bucketsCount - 1, rainDrops = 0;
    for (; rainDrops < n && remaining > 0; rainDrops++)
    {
        int bucketIdx = first / D;
        int oldStart = buckets[bucketIdx].start;
        int oldEnd = buckets[bucketIdx].end;
        buckets[bucketIdx].expand(first);

        int changePrev = 0, changeNext = 0;
        if (bucketIdx) // Check if we have prev element
        {
            // check if distance between previous bucket and current bucket was greater than D and if now it is smaller than D
            changePrev = oldStart - buckets[bucketIdx - 1].end > D && buckets[bucketIdx].start - buckets[bucketIdx - 1].end <= D;
        }
        if (bucketIdx + 1 < bucketsCount) // Check if we have next element
        {
            // check if distance between current bucket and next bucket was greater than D and if now it is smaller than D
            changeNext = buckets[bucketIdx + 1].start - oldEnd > D && buckets[bucketIdx + 1].start - buckets[bucketIdx].end <= D;
        }
        remaining -= (changePrev + changeNext);

        first = ((long long)first * A + B) % ((long long)potLength + 1);
    }

    cout << (remaining == 0 ? rainDrops : -1);

    return 0;
}