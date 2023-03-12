#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, c[100][100], x[100], visited[100], ans = INT_MAX, cmin;
vector<int> path;
void Try(int i, int sum)
{
    for (int j = 2; j <= n; j++)
    {
        if (!visited[j])
        {
            x[i] = j;
            visited[j] = 1;
            sum += c[x[i - 1]][x[i]];
            if (i == n)
            {
                if (ans > sum + c[x[i]][1])
                {
                    path.clear();
                    ans = sum + c[x[i]][1];
                    for (int k = 1; k <= i + 1; k++)
                    {
                        if (k == i + 1)
                        {
                            path.push_back(x[1]);
                            continue;
                        }
                        path.push_back(x[k]);
                    }
                }
            }
            else if (sum + (n - i + 1) * cmin < ans)
            {
                Try(i + 1, sum);
            }
            visited[j] = 0;
            sum -= c[x[i - 1]][x[i]];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j])
                cmin = min(cmin, c[i][j]);
        }
    }
    x[1] = 1;
    visited[1] = 1;
    Try(2, 0);
    cout << "(";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1)
            cout << ",";
    }
    cout << ")";
    cout << endl;
    cout << ans << endl;
}