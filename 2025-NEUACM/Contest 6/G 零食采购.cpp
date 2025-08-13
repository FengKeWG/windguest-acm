#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
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

struct Node
{
    int l, r;
    int m;
} t[N * 4];

vector<int> e[N];
int w[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N], nw[N];
int cnt;
int n, q;

void up(int r)
{
    t[r].m = t[ls].m | t[rs].m;
}

int qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (x <= t[r].l && t[r].r <= y)
        return t[r].m;
    return (qsum(ls, x, y) | qsum(rs, x, y));
}

int qsump(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res |= qsum(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    res |= qsum(1, id[v], id[u]);
    return res;
}

void build(int r, int x, int y)
{
    t[r] = {x, y};
    if (x == y)
    {
        t[r].m |= (1 << nw[x] - 1);
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void dfs1(int u, int fat)
{
    fa[u] = fat, dep[u] = dep[fat] + 1, sz[u] = 1;
    for (auto &v : e[u])
    {
        if (v != fat)
        {
            dfs1(v, u);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    }
}

void dfs2(int u, int t)
{
    top[u] = t, id[u] = ++cnt, nw[cnt] = w[u];
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (auto &v : e[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    while (q--)
    {
        int s = read(), t = read();
        int m = qsump(s, t);
        int cnt = 0;
        for (int i = 0; i <= 20; i++)
            if (m >> i & 1)
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}