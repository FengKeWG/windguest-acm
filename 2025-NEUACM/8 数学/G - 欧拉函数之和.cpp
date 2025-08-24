#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define N 100000005
#define mod 998244353
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

bool vis[N];
int pr[N];
int ph[N];
int cnt;

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

int phi(int n)
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

void get_phi(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++cnt] = i;
            ph[i] = i - 1;
        }
        for (int j = 1; i * pr[j] <= n; j++)
        {
            int m = i * pr[j];
            vis[m] = 1;
            if (i % pr[j] == 0)
            {
                ph[m] = pr[j] * ph[i];
                break;
            }
            else
                ph[m] = (pr[j] - 1) * ph[i];
        }
    }
}

int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    get_phi(n);
    ph[1] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[ph[i]] == 0)
            a[ph[i]] = qpow(ph[i], k);
        ans = (ans + a[ph[i]]) % mod;
    }
    cout << ans << endl;
    return 0;
}