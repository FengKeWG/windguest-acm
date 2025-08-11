#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

int a[N];
int f[N];
int g[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
        {
            g[i] = -inf;
            f[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            f[i] = f[i - 1];
            if (g[a[i]] != -inf)
                f[i] = max(f[i], g[a[i]] + i);
            g[a[i]] = max(g[a[i]], f[i - 1] - i + 1);
            // if (!g[a[i]])
            // {
            //     f[i][1] = 0;
            //     f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            //     g[a[i]] = i;
            // }
            // else
            // {
            //     f[i][1] = max(f[i][1], f[g[a[i]]][0] + i - g[a[i]] + 1);
            //     f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            // }
        }
        cout << f[n] << endl;
        // for (int i = 1; i <= n; i++)
        //     cout << f[i][0] << " " << f[i][1] << endl;
    }
    return 0;
}