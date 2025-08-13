#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1005
#define M 100005
// #define mod 1000000007
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

int f[N][N];
int a[N];

signed main()
{
    int n = read(), m = read(), b = read(), mod = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] <= b)
                for (int k = a[i]; k <= b; k++)
                {
                    f[j][k] = f[j - 1][k - a[i]] % mod + f[j][k] % mod;
                    f[j][k] = f[j][k] % mod;
                }
    int ans = 0;
    for (int i = 0; i <= b; i++)
        ans = (ans + f[m][i]) % mod;
    cout << ans << endl;
    return 0;
}