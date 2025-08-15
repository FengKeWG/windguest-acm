#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2005
#define M 100005
#define mod 1000000007
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
int S[N][N];
int P[N][N];

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

void init()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * qpow(i, mod - 2) % mod;
    }
    S[0][0] = 1;
    for (int n = 1; n < N; n++)
        for (int k = 1; k <= n; k++)
            S[n][k] = (S[n - 1][k - 1] + k * S[n - 1][k] % mod) % mod;
    for (int k = 0; k < N; k++)
        P[0][k] = 1;
    for (int n = 1; n < N; n++)
        P[n][0] = 0;
    for (int n = 1; n < N; n++)
    {
        for (int k = 1; k < N; k++)
        {
            P[n][k] = P[n][k - 1];
            if (n >= k)
            {
                P[n][k] += P[n - k][k];
                if (P[n][k] >= mod)
                    P[n][k] -= mod;
            }
        }
    }
}

int C(int a, int b)
{
    if (b < 0 || b > a)
        return 0;
    return f[a] * g[b] % mod * g[a - b] % mod;
}

int A(int a, int b)
{
    if (b < 0 || b > a)
        return 0;
    return f[a] % mod * g[a - b] % mod;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    int T = read();
    while (T--)
    {
        int c = read(), n = read(), k = read();
        if (c == 1)
            cout << qpow(k, n) << endl;
        if (c == 2)
            cout << (n <= k ? A(k, n) : 0) << endl;
        if (c == 3)
            cout << (n >= k ? S[n][k] * f[k] % mod : 0) << endl;
        if (c == 4)
            cout << C(n + k - 1, k - 1) << endl;
        if (c == 5)
            cout << (n <= k ? C(k, n) : 0) << endl;
        if (c == 6)
            cout << (n >= k ? C(n - 1, k - 1) : 0) << endl;
        if (c == 7)
        {
            int ans = 0;
            int up = min(n, k);
            for (int i = 1; i <= up; i++)
            {
                ans += S[n][i];
                if (ans >= mod)
                    ans -= mod;
            }
            cout << ans << endl;
        }
        if (c == 8)
            cout << (n <= k ? 1 : 0) << endl;
        if (c == 9)
            cout << (n >= k ? S[n][k] : 0) << endl;
        if (c == 10)
            cout << P[n][k] << endl;
        if (c == 11)
            cout << (n <= k ? 1 : 0) << endl;
        if (c == 12)
            cout << (n >= k ? P[n - k][k] : 0) << endl;
    }
    return 0;
}