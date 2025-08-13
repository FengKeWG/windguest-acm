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
    int l, r, add, sum;
} t[N * 4];

vector<int> e[N];
int w[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N], nw[N];
int cnt;

int n, m, r, p;

void calc(Node &t, int add)
{
    t.sum = (t.sum + (t.r - t.l + 1) * add) % p;
    t.add = (t.add + add) % p;
}

void up(int r)
{
    t[r].sum = (t[ls].sum + t[rs].sum) % p;
}

void down(int r)
{
    calc(t[ls], t[r].add);
    calc(t[rs], t[r].add);
    t[r].add = 0;
}

int qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (x <= t[r].l && t[r].r <= y)
        return t[r].sum;
    down(r);
    return (qsum(ls, x, y) + qsum(rs, x, y)) % p;
}

void upd(int r, int x, int y, int add)
{
    if (t[r].l > y || t[r].r < x)
        return;
    if (x <= t[r].l && t[r].r <= y)
    {
        calc(t[r], add);
        return;
    }
    down(r);
    upd(ls, x, y, add);
    upd(rs, x, y, add);
    up(r);
}

void updp(int u, int v, int add)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        upd(1, id[top[u]], id[u], add);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    upd(1, id[v], id[u], add);
}

int qsump(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res += qsum(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    res = (res + qsum(1, id[v], id[u])) % p;
    return res;
}

void updt(int u, int v)
{
    upd(1, id[u], id[u] + sz[u] - 1, v);
}

int qsumt(int u)
{
    return qsum(1, id[u], id[u] + sz[u] - 1);
}

void build(int r, int x, int y)
{
    t[r] = {x, y, 0, nw[x] % p};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void dfs1(int u, int f)
{
    fa[u] = f, dep[u] = dep[f] + 1, sz[u] = 1;
    for (auto &v : e[u])
    {
        if (v != f)
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
    n = read(), m = read(), r = read(), p = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    while (m--)
    {
        int op = read();
        if (op == 1)
        {
            int x = read(), y = read(), z = read();
            updp(x, y, z);
        }
        else if (op == 2)
        {
            int x = read(), y = read();
            cout << qsump(x, y) % p << endl;
        }
        else if (op == 3)
        {
            int x = read(), y = read();
            updt(x, y);
        }
        else
        {
            int x = read();
            cout << qsumt(x) % p << endl;
        }
    }
    return 0;
}