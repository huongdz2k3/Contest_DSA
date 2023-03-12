#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

ll a, b;

void solve()
{
    cin >> a >> b;
    ll c0 = 0;
    ll c1 = 0;
    ll c2 = 0;
    ll c3 = 0;
    ll c4 = 0;
    ll c5 = 0;
    ll c6 = 0;
    ll c7 = 0;
    ll c9 = 0;
    ll c8 = 0;
    for (ll i = a; i <= b; i++)
    {
        ll r = i;
        while (r > 0)
        {
            int h = r % 10;
            if (h == 0)
                c0++;
            if (h == 1)
                c1++;
            if (h == 2)
                c2++;
            if (h == 3)
                c3++;
            if (h == 4)
                c4++;
            if (h == 5)
                c5++;
            if (h == 7)
                c7++;
            if (h == 8)
                c8++;
            if (h == 9)
                c9++;
            r /= 10;
        }
    }
    cout << c0 << " " << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}