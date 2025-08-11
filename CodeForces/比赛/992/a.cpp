#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            bool can = 1;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (abs(a[i] - a[j]) % k == 0)
                {
                    can = 0;
                    break;
                }
            }
            if (can)
            {
                ans = i;
                break;
            }
        }
        if (ans)
        {
            cout << "Yes" << endl
                 << ans << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}