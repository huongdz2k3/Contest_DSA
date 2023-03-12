#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int wei[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wei[i] >> val[i];
    }
    int dp[m + 5] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= wei[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - wei[i]] + val[i]);
        }
    }
    cout << dp[m] << endl;
}