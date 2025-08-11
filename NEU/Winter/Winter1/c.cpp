#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define MOD 9999973
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

inline int C(int x)
{
    return (x * (x - 1) / 2) % MOD;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int f[105][105][105];
    f[0][0][0] = 1;
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; j + k <= m && j + k <= 2 * i; k++)
            {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % MOD;
                if (j >= 1)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k] * (m - (j - 1) - k) % MOD) % MOD;
                if (k >= 1)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j + 1][k - 1] * (j + 1) % MOD) % MOD;
                if (j >= 2)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j - 2][k] * C(m - (j - 2) - k) % MOD) % MOD;
                if (k >= 1)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1] * j % MOD * (m - j - (k - 1)) % MOD) % MOD;
                if (k >= 2)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j + 2][k - 2] * C(j + 2) % MOD) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; i + j <= m && i + j <= 2 * n; j++)
            ans = (ans + f[n][i][j]) % MOD;
    cout << ans;

    return 0;
}