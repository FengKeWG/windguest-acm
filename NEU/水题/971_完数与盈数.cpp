#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int m, n;
    cin >> m >> n;
    vector<int> e, g;
    for (int i = m; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i / j; j++)
        {
            if (i % j == 0)
            {
                sum += j;
                if (j * j != i && j != 1)
                    sum += i / j;
            }
        }
        if (sum == i)
            e.push_back(i);
        else if (sum > i)
            g.push_back(i);
    }

    cout << "E:";
    for (auto &x : e)
        cout << " " << x;
    cout << endl
         << "G:";
    for (auto &x : g)
        cout << " " << x;

    return 0;
}