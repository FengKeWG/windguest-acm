#include <bits/stdc++.h>
#define int long long
#define inf LLONG_MAX / 2
#define endl '\n'
#define pii pair<int, int>
#define N 10000005
using namespace std;

int t[N], p[N], c[N];

signed main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> p[i] >> c[i];
    int ans = inf;
    int ans2 = inf;
    for (int m = 0; m < (1 << n); m++)
    {
        // int m = 7;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if ((m >> i) & 1)
                cnt++;
        if (cnt > k)
            continue;
        int res1 = 0, res2 = 0;
        bool can = 1;
        int now = 0;
        bool has = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if ((m >> i) & 1)
            {
                if (now == 0)
                {
                    can = 0;
                    break;
                }
                res1 += t[now] * p[n - i];
                res2 += c[n - i];
            }
            else
            {
                now = n - i;
                res1 += t[now] * p[now];
            }
        }
        if (can)
        {
            if (res1 < ans)
            {
                ans = res1;
                ans2 = res2;
            }
            else if (res1 == ans)
                ans2 = min(ans2, res2);
        }
    }
    cout << ans << ' ' << ans2 << endl;
    return 0;
}