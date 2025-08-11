#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 505
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

vector<int> e[N], ne[N];
int din[N];

int n, m;
int f[M][M];
int sz[N];
int w[N], c[N];
int dfn[N], low[N], tot;
int scc[N], cnt;
stack<int> s;
bool ins[N];
int nw[N], nc[N];

void dfs_scc(int u)
{
    dfn[u] = low[u] = ++tot;
    s.push(u);
    ins[u] = 1;
    for (auto &v : e[u])
    {
        if (!dfn[v])
        {
            dfs_scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v;
        cnt++;
        do
        {
            v = s.top();
            s.pop();
            ins[v] = 0;
            scc[v] = cnt;
        } while (u != v);
    }
}

void dfs(int u)
{
    if (nw[u] <= m)
        f[u][nw[u]] = nc[u];
    for (auto &v : ne[u])
    {
        dfs(v);
        for (int j = m; j >= nw[u]; j--)
            for (int k = 0; k <= j - nw[u]; k++)
            {
                if (f[u][j - k] == -inf || f[v][k] == -inf)
                    continue;
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
            }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 1; i <= n; i++)
    {
        int u = read();
        e[u].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs_scc(i);
    for (int u = 1; u <= n; u++)
    {
        nw[scc[u]] += w[u];
        nc[scc[u]] += c[u];
        for (auto &v : e[u])
        {
            int x = scc[u], y = scc[v];
            if (x != y)
                ne[x].push_back(y);
        }
    }
    for (int i = 1; i <= cnt; i++)
        for (auto &v : ne[i])
            din[v]++;
    int r = cnt + 1;
    for (int i = 1; i <= cnt; ++i)
        if (din[i] == 0)
            ne[r].push_back(i);
    nw[r] = 0, nc[r] = 0;
    memset(f, -inf, sizeof f);
    dfs(r);
    long long ans = 0;
    for (int j = 0; j <= m; ++j)
        ans = max(ans, f[r][j]);
    cout << ans << endl;
    return 0;
}