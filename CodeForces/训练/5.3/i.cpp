#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 100005
#define M 100005
#define MOD 998244353
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n, k;
int a[N], b[N];
int f[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    if (n < k)
    {
        cout << 0 << endl;
        return 0;
    }
    f[0] = 1;
    for (int i = 1; i <= k; i++)
        f[i] = (f[i - 1] * i) % MOD;
    for (int i = 1; i <= k; ++i)
    {
        b[i] = f[i];
        int sum = 0;
        for (int j = 1; j < i; j++)
            sum = (sum + (b[j] * f[i - j]) % MOD) % MOD;
        b[i] = (b[i] - sum + MOD) % MOD;
    }
    a[k] = f[k];
    for (int i = k + 1; i <= n; i++)
    {
        a[i] = 0;
        for (int j = 1; j <= k; j++)
        {
            int t = (a[i - j] * b[j]) % MOD;
            a[i] = (a[i] + t) % MOD;
        }
    }
    cout << a[n] << endl;
    return 0;
}