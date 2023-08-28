#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BUCKET_SIZE = 50000;

int n, k;
long long int FIRST, MUL, ADD, MOD;

int buckets[50000];
int targetBucket[BUCKET_SIZE];

int main()
{
    // условие: https://action.informatika.bg/problems/162

    cin >> k >> n >> FIRST >> MUL >> ADD >> MOD;

    // Fill the buckets
    int curElem = FIRST;
    ++buckets[FIRST / BUCKET_SIZE];
    for (int i = 1; i < n; ++i)
    {
        curElem = ((long long)curElem * MUL + ADD) % MOD;
        ++buckets[curElem / BUCKET_SIZE];
    }

    // Find in which bucket is our element and his position in the bucket
    int elemsCnt = buckets[0], bucketInd = 0, posInBucket = k;
    while (elemsCnt < k)
    {
        posInBucket = k - elemsCnt;
        elemsCnt += buckets[++bucketInd];
    }

    // Do counting of the elements in the target bucket
    curElem = FIRST;
    if (FIRST / BUCKET_SIZE == bucketInd)
        ++targetBucket[FIRST % BUCKET_SIZE];
    for (int i = 1; i < n; ++i)
    {
        curElem = ((long long)curElem * MUL + ADD) % MOD;
        if (curElem / BUCKET_SIZE == bucketInd)
        {
            ++targetBucket[curElem % BUCKET_SIZE];
        }
    }

    // Iterate counts till finding posInBucket
    int i = 0;
    while (posInBucket > 0)
    {
        posInBucket -= targetBucket[i];
        if (posInBucket > 0)
            ++i;
    }

    // Formula for result is (Index + BEGIN_OF_BUCKET)
    printf("%d", i + bucketInd * BUCKET_SIZE);

    return 0;
}