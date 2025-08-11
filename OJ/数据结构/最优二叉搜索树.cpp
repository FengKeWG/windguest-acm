#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 505
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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

int n;
double p[N], q[N];
double f[N][N];
double w[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 0; i <= n; i++)
        cin >> q[i];
    // memset(f, inf, sizeof f);
    for (int i = 1; i <= n + 1; i++)
    {
        f[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
        for (int j = i; j <= n; j++)
            w[i][j] = w[i][j - 1] + p[j] + q[j];
    }
    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            f[l][r] = inf;
            for (int k = l; k <= r; k++)
                f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r] + w[l][r]);
        }
    cout << fixed << setprecision(8) << f[1][n];
    return 0;
}