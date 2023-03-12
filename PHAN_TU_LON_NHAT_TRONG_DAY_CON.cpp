#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int &x : a)
            cin >> x;
        multiset<int> ms;
        for (int i = 0; i < k; i++)
            ms.insert(a[i]);
        cout << *ms.rbegin() << " ";
        for (int i = k; i < n; i++)
        {
            ms.erase(ms.find(a[i - k]));
            ms.insert(a[i]);
            cout << *ms.rbegin() << " ";
        }
        cout << endl;
    }
}