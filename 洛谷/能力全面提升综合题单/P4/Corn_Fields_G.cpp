#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 15
#define M 100005
#define MOD 100000000
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, m;
int x;
int g[N];
int s[1 << N];
int cnt;
int num[1 << N];
int f[N][1 << N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    // g[0] = g[n + 1] = (1 << m) - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            x = read();
            g[i] += x * (1 << m - j);
        }
    for (int i = 0; i < (1 << m); i++)
    {
        if (!(i & i << 1))
        {
            s[++cnt] = i;
            for (int j = 0; j < m; j++)
                num[i] += (i >> j & 1);
        }
    }
    for (int a = 1; a <= cnt; a++)
        f[0][a] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int a = 1; a <= cnt; a++)
            for (int b = 1; b <= cnt; b++)
            {
                if (s[a] & ~g[i] || s[b] & ~g[i - 1] || s[a] & s[b])
                    continue;
                f[i][a] += f[i - 1][b];
                // cout << f[i][a] << endl;
            }
    // for (int a = 1; a <= cnt; a++)
    //     cout << bitset<3>(s[a]) << " " << f[1][a] << endl;
    // for (int a = 1; a <= cnt; a++)
    //     cout << bitset<3>(s[a]) << " " << f[2][a] << endl;
    cout << f[n + 1][1] % MOD << endl;
    return 0;
}