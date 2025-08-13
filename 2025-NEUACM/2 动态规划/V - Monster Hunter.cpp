#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f3f3f3fll
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

int n;
int a[N];
vector<int> e[N];
int f[N][N][2], g[N][2];
int sz[N];

void dfs(int u)
{
    sz[u] = 1;
    f[u][0][0] = 0;
    f[u][1][1] = a[u];
    for (auto &v : e[u])
    {
        dfs(v);
        for (int i = 0; i <= sz[u] + sz[v]; i++)
            g[i][0] = g[i][1] = inf;
        for (int i = 0; i <= sz[u]; i++)
            for (int j = 0; j <= sz[v]; j++)
            {
                if (f[u][i][0] != inf)
                {
                    int w = min(f[v][j][0], f[v][j][1]);
                    if (w != inf)
                        g[i + j][0] = min(g[i + j][0], f[u][i][0] + w);
                }
                if (f[u][i][1] != inf)
                {
                    if (f[v][j][0] != inf)
                        g[i + j][1] = min(g[i + j][1], f[u][i][1] + f[v][j][0]);
                    if (f[v][j][1] != inf)
                        g[i + j][1] = min(g[i + j][1], f[u][i][1] + f[v][j][1] + a[v]);
                }
            }
        sz[u] += sz[v];
        for (int i = 0; i <= sz[u]; i++)
        {
            f[u][i][0] = g[i][0];
            f[u][i][1] = g[i][1];
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 2; i <= n; i++)
        {
            int u = read();
            e[u].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                f[i][j][0] = f[i][j][1] = inf;
        dfs(1);
        for (int i = 0; i <= n; i++)
            cout << min(f[1][n - i][0], f[1][n - i][1]) << " ";
        cout << endl;
    }
    return 0;
}