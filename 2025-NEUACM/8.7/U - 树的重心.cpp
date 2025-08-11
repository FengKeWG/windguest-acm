#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, fa = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            fa = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * fa;
}

int T, n;
vector<int> e[N];
int sz[N], fa[N], s[N][18], s2[N];
int ans;

bool check(int u, int n)
{
    return max(n - sz[u], sz[s[u][0]]) <= n / 2;
}

void dfs(int u, int f)
{
    sz[u] = 1, fa[u] = f, s[u][0] = s2[u] = 0;
    for (int v : e[u])
    {
        if (v == f)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[s[u][0]] < sz[v])
            s2[u] = s[u][0], s[u][0] = v;
        else if (sz[s2[u]] < sz[v])
            s2[u] = v;
    }
}

void dfs2(int u, int f)
{
    int son = s[u][0], szu = sz[u];
    fa[f] = u;
    for (int v : e[u])
    {
        if (v == f)
            continue;
        s[u][0] = (v == son ? s2[u] : son);
        if (sz[f] > sz[s[u][0]])
            s[u][0] = f;
        for (int k = 1; k <= 17; k++)
            s[u][k] = s[s[u][k - 1]][k - 1];
        sz[u] = n - sz[v], fa[u] = 0, fa[v] = 0;
        int p = u;
        for (int k = 17; k >= 0; k--)
            if (sz[u] - sz[s[p][k]] <= sz[u] / 2)
                p = s[p][k];
        ans += p + fa[p] * check(fa[p], sz[u]);
        p = v;
        for (int k = 17; k >= 0; k--)
            if (sz[v] - sz[s[p][k]] <= sz[v] / 2)
                p = s[p][k];
        ans += p + fa[p] * check(fa[p], sz[v]);
        dfs2(v, u);
    }
    s[u][0] = son, sz[u] = szu, fa[u] = f;
    for (int k = 1; k <= 17; k++)
        s[u][k] = s[s[u][k - 1]][k - 1];
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        ans = 0;
        n = read();
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v), e[v].push_back(u);
        }
        dfs(1, 0);
        for (int k = 1; k <= 17; k++)
            for (int i = 1; i <= n; i++)
                s[i][k] = s[s[i][k - 1]][k - 1];
        dfs2(1, 0);
        cout << ans << endl;
    }
}