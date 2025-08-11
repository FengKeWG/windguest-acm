#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1000005
#define MOD 1000000007
#define eps 1e-6
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

int d[MAXN];
int f[MAXN], inv[MAXN];

int qpow(int a, int b)
{
    int res = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void pre()
{
    f[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        f[i] = f[i - 1] * i % MOD;
        inv[i] = qpow(f[i], MOD - 2);
    }
    d[0] = 1, d[2] = 1;
    for (int i = 3; i <= MAXN; i++)
    {
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
    }
}

int C(int a, int b)
{
    return f[a] * inv[b] % MOD * inv[a - b] % MOD;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        if (m == n)
            cout << 1 << endl;
        else if (m == 0)
            cout << d[n] << endl;
        else
            cout << C(n, m) * d[n - m] % MOD << endl;
    }

    return 0;
}