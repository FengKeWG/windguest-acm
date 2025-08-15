#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
#define M 100005
#define mod 20100403
#define eps 1e-6
#define inf (LLONG_MAX >> 1)
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

int f[N], g[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    return f[a] * g[b] % mod * g[a - b] % mod;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * qpow(i, mod - 2) % mod;
    }
    cout << (C(n + m, n) - C(n + m, n + 1) + mod) % mod;
    return 0;
}