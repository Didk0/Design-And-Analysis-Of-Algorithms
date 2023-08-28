#include <iostream>
#include <algorithm>
using namespace std;

int n, q;
int shoes[100005];
long long int prefix[1000005];

int binary_search(int shoe)
{
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (shoes[mid] > shoe)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int binary_search_pairs(int start, int money)
{
    int left = start, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        long long int currSum;
        if (start == 0)
        {
            currSum = prefix[mid];
        }
        else
        {
            currSum = prefix[mid] - prefix[start - 1];
        }
        if (currSum <= money)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left - start;
}

int main()
{
    // условие: https://action.informatika.bg/problems/28

    scanf_s("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &shoes[i]);
    }

    sort(shoes, shoes + n, [](int s1, int s2) {return s1 > s2; });

    prefix[0] = shoes[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + shoes[i];
    }

    int money, upperLimit;
    for (int i = 0; i < q; i++)
    {
        scanf_s("%d %d", &money, &upperLimit);
        int pos = binary_search(upperLimit);
        printf("%d\n", binary_search_pairs(pos, money));
    }

    return 0;
}
