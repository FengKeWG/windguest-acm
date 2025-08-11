#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    vector<int> a(n);
    int maxg = 0;
    for (auto &x : a)
    {
        x = read();
        maxg = max(maxg, x);
    }
    int ansg = 0;
    int ans = 0;
    int l = 1, r = maxg;
    while (l <= r)
    {
        int g = (l + r) >> 1;
        int cnt = 1;
        bool can = 1;
        for (auto &x : a)
        {
            if (x < g)
            {
                can = 0;
                break;
            }
            else
            {
                cnt *= x / g;
                cnt %= MOD;
            }
        }
        if (can)
        {
            ansg = g;
            ans = cnt;
            l = g + 1;
        }
        else
        {
            r = g - 1;
        }
    }
    cout << ansg << " " << ans;
    return 0;
}