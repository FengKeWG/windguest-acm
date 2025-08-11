#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100020
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

/*
C(n,m) = C(n/p, m/p) C(m mod p, n mod p)  (mod p)
*/

int f[N], g[N];

int qpow(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void pre(int p)
{
    f[0] = g[0] = 1;
    for (int i = 1; i <= p; i++)
    {
        f[i] = f[i - 1] * i % p;
        g[i] = g[i - 1] * qpow(i, p - 2, p) % p;
    }
}

int C(int n, int m, int p)
{
    if (m > n)
        return 0;
    return f[n] * g[m] * g[n - m] % p;
}

int lucas(int n, int m, int p)
{
    if (m == 0)
        return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while (T--)
    {
        // int n = read(), m = read(), p = read();
        pre(100007);
        cout << C(3, 1, 100007) << endl;
    }
    return 0;
}