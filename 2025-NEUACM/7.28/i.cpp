#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

int a[N], b[N];
bool vis[N];
// int f[N][2][2];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    // for (int i = 1; i <= n; i++)
    // {
    //     if (f[i - 1][0][0] > f[i - 1][0][1])
    //     {
    //         f[i][0][0] = f[i - 1][0][0];
    //         f[i][0][1] = f[i - 1][0][1] + a[i];
    //     }
    //     else
    //     {
    //         f[i][0][0] = f[i - 1][1][0];
    //         f[i][0][1] = f[i - 1][1][1] + a[i];
    //     }
    //     if (f[i - 1][0][1] + a[i] >= b[i])
    //     {
    //         f[i][1][0] = f[i - 1][1][0] + 1;
    //         f[i][1][1] = f[i - 1][0][1] + a[i] - b[i];
    //     }
    // }
    // cout << max(f[n][1][0], f[n][0][1]);
    priority_queue<pii> q;
    int res = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        res += a[i];
        if (res <= b[i] && q.size())
        {
            if (q.top().first > b[i])
            {
                auto [x, t] = q.top();
                vis[t] = 0;
                res += x;
                q.pop();
                ans--;
            }
        }
        if (res >= b[i])
        {
            res -= b[i];
            ans++;
            q.push({b[i], i});
            vis[i] = 1;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (vis[i])
            cout << i << ' ';
    return 0;
}