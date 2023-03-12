#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[10000005];
bool dd[10000010] = {};
bool check(int n)
{
    if (n == 1 || !dd[n])
        return 0;
    double sqr = sqrt(n);
    int pre = n, cnt = 0;
    ll res = 1;
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
        {
            cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            sqr = sqrt(n);
            ll next = i;
            ll tmp = 1;
            for (int j = 1; j <= cnt; j++)
            {
                tmp += next;
                next *= i;
            }
            res *= tmp;
        }
        if (!dd[n])
            break;
    }
    if (n > 1)
        res *= (n + 1);
    res -= pre;
    return res > pre;
}
int main()
{
    int l, r, cnt = 0;
    cin >> l >> r;
    double sqr = sqrt(r);
    dd[0] = dd[1] = 1;
    for (int i = 2; i <= sqr; i++)
    {
        if (!dd[i])
        {
            for (int j = i * i; j <= r; j += i)
                dd[j] = 1;
        }
    }
    for (int i = l; i <= r; i++)
        if (check(i))
            cnt++;
    cout << cnt;
}