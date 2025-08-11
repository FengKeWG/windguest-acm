#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 55
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

int a[N], w[N];
int s[N];
int f[N][N][2];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), c = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), w[i] = read();
        s[i] = s[i - 1] + w[i];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j][0] = f[i][j][1] = inf;
    f[c][c][0] = f[c][c][1] = 0;
    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int pos = 0;
            int r = l + len - 1;
            for (int k = 0; k <= 1; k++)
            {
                if (f[l][r][k] == inf)
                    continue;
                int res = s[n] - s[r] + s[l - 1];
                if (k == 0)
                    pos = a[l];
                else
                    pos = a[r];
                if (l > 1)
                {
                    int dis = abs(pos - a[l - 1]);
                    f[l - 1][r][0] = min(f[l - 1][r][0], f[l][r][k] + res * dis);
                }
                if (r < n)
                {
                    int dis = abs(pos - a[r + 1]);
                    f[l][r + 1][1] = min(f[l][r + 1][1], f[l][r][k] + res * dis);
                }
            }
        }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << f[i][j][0] << " " << f[i][j][1] << " ";
    //     cout << endl;
    // }
    cout << min(f[1][n][0], f[1][n][1]) << endl;
    return 0;
}