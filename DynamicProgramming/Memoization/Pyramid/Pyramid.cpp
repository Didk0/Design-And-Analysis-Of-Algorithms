#include <iostream>
using namespace std;

int dp[52];
// dp[i] -> най-високата възможна кула, която приключва в i-тия камък

pair<int, int> pebbles[52];
int n;

bool in(int p1, int p2)
{
    return pebbles[p1].first <= pebbles[p2].first && pebbles[p1].second >= pebbles[p2].second;
}

int solve(int p)
{
    if (p == 0)
    {
        return 1;
    }

    if (dp[p] > 0)
    {
        return dp[p];
    }

    int res = 1;
    for (int i = p-1; i >= 0; i--)
    {
        if (in(i,p)) 
        {
            // Можем да ги сложим една върху друга
            res = max(res, solve(i) + 1);
        }
    }
    return dp[p] = res;
}

int main()
{
    // условие: https://action.informatika.bg/problems/196

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> pebbles[i].first >> pebbles[i].second;
    }

    int ans = solve(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        if (dp[i] == 0)
            ans = max(ans, solve(i));
        else
            ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}
