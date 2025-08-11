#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

int a[355], cnt[5];
int f[42][42][42][42];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read();
        cnt[x]++;
    }
    f[0][0][0][0] = a[1];
    for (int i = 0; i <= cnt[1]; i++)
        for (int j = 0; j <= cnt[2]; j++)
            for (int k = 0; k <= cnt[3]; k++)
                for (int l = 0; l <= cnt[4]; l++)
                {
                    if (i > 0)
                        f[i][j][k][l] = max(f[i][j][k][l], f[i - 1][j][k][l] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                    if (j > 0)
                        f[i][j][k][l] = max(f[i][j][k][l], f[i][j - 1][k][l] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                    if (k > 0)
                        f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k - 1][l] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                    if (l > 0)
                        f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l - 1] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                }
    cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
    return 0;
}