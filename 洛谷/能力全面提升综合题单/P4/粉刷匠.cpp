#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 55
#define M 2505
#define MOD 1000000007
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

int n, m, t;
string a[N];
int s[N][N]; // 蓝色格子数目
int f[M];
int g[N][N][M];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = ' ' + a[i];
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= j; k++)
                if (a[i][k] == '1')
                    s[i][j]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)     // 前几个格子
            for (int k = 1; k <= j; k++) // 涂了多少次
                for (int l = 0; l < j; l++)
                {
                    g[i][j][k] = max(g[i][j][k], g[i][l][k - 1] + s[i][j] - s[i][l]);
                    g[i][j][k] = max(g[i][j][k], g[i][l][k - 1] + j - l - s[i][j] + s[i][l]);
                }
        // for (int k = 1; k <= m; k++)
        //     cout << g[i][m][k] << " ";
        // cout << endl;
    }
    for (int i = 1; i <= n; i++)
        for (int j = t; j >= 1; j--)
            for (int k = 1; k <= m; k++)
                if (j >= k)
                    f[j] = max(f[j], f[j - k] + g[i][m][k]);
    cout << f[t] << endl;
    return 0;
}