
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0;
    int M = *max_element(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (a[j] == M && j <= n)
            j++;
        res = max(res, j - i);
        if (j > i)
            i = j - 1;
    }
    cout << res << "\n";
}