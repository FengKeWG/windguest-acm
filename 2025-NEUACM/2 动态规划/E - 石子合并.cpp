#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
// #define mid ((t[r].l + t[r].r) >> 1)
// #define lson (r << 1)
// #define rson (r << 1 | 1)
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

int n;
int a[N];
int s[N];
int f[N][N];
int g[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    memset(f, 0x3f3f3f3f, sizeof(f));
    memset(g, -0x3f3f3f3f, sizeof(g));
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
        f[i][i] = 0;
        g[i][i] = 0;
    }
    for (int i = n + 1; i <= n << 1; i++)
    {
        a[i] = a[i - n];
        s[i] = s[i - 1] + a[i];
        f[i][i] = 0;
        g[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n << 1; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    int mi = inf, mx = -inf;
    for (int i = 1; i <= n; i++)
    {
        mi = min(mi, f[i][i + n - 1]);
        mx = max(mx, g[i][i + n - 1]);
    }
    cout << mi << endl
         << mx;
    return 0;
}