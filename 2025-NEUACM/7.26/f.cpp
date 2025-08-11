#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 20
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

int w[N], h[N], q[N];
int s[1 << N];
int f[N][1 << N];
// int tot;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
        w[i] = read(), h[i] = read(), q[i] = read();
    // for (int m = 0; m < 1 << n; m++)
    // {
    //     int cnt = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (m << j & 1)
    //             cnt++;
    //     }
    //     if (cnt <= k)
    //         s[++tot] = m;
    // }
    for (int m = 0; m < 1 << n; m++)
    {
        int W = 0, H = 0;
        for (int i = 1; i <= n; i++)
            if (m & 1 << i - 1)
            {
                W = max(W, w[i]);
                H = max(H, h[i]);
            }
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (m & 1 << i - 1)
                res += q[i] * (W * H - w[i] * h[i]);
        s[m] = res;
    }
    memset(f, inf, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= k; i++)
        for (int m = 0; m < 1 << n; m++)
        {
            f[i][m] = f[i - 1][m];
            for (int r = m; r > 0; r = r - 1 & m) // r选
            {
                int p = f[i - 1][m ^ r]; // 未选
                if (p == inf)
                    continue;
                f[i][m] = min(f[i][m], p + s[r]);
            }
        }
    cout << f[k][(1 << n) - 1] << endl;
    return 0;
}