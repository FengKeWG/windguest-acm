#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 19
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int f[1 << N], g[1 << N];
int a[N];

signed main()
{
    int n = read(), W = read();
    for (int i = 0; i < n; i++)
        a[i] = read();
    memset(f, 0x3f3f3f3f3f, sizeof f);
    f[0] = 0;
    // for (int i = 0; i < (1 << n); i++)
    // {
    //     int res = 0;
    //     for (int j = 0; j < n; j++)
    //         res += (i >> j & 1) * a[j];
    //     // cout << res << endl;
    //     if (res <= W)
    //     {
    //         s[cnt++] = i;
    //         // for (int j = 0; j < n; j++)
    //         //     num[i] += i >> j & 1;
    //     }
    // }
    for (int i = 1; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i & (1 << j)))
                continue;
            int s = (i ^ (1 << j));
            if (g[s] >= a[j] && f[i] >= f[s])
            {
                if (f[i] == f[s])
                    g[i] = max(g[i], g[s] - a[j]);
                else
                    g[i] = g[s] - a[j];
                f[i] = f[s];
            }
            else if (g[s] < a[j] && f[i] > f[s])
            {
                if (f[i] == f[s] + 1)
                    g[i] = max(g[i], max(g[s], W - a[j]));
                else
                    g[i] = max(g[s], W - a[j]);
                f[i] = f[s] + 1;
            }
        }
    }
    printf("%d\n", f[(1 << n) - 1]);
    return 0;
}