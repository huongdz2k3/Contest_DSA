#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
int a[1000005];
int lef[1000005], rig[1000005];
int lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

void run_case()
{
    cin >> n;
    for (int &x : a)
        cin >> x;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (st.size() && a[st.top()] <= a[i])
        {
            st.pop();
        }

        lef[i] = st.empty() == true ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        rig[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (ll)(i - lef[i]) * (rig[i] - i) * a[i];
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        run_case();
    }
}