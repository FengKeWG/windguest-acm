#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 10005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX / 2
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
    int l, r, add, sum, min;
} t[N * 4];

struct edge
{
    int u, v, w;
    bool operator<(const edge &t) const
    {
        return w > t.w;
    }
} E[100005];

struct node
{
    int v, w;
};
vector<node> e[N];
int F[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N], nw[N];
int cnt;

int n, m, r;

void calc(Node &t, int add)
{
    t.sum += (t.r - t.l + 1) * add;
    t.min += add;
    t.add = t.add + add;
}

void up(int r)
{
    t[r].sum = (t[ls].sum + t[rs].sum);
    t[r].min = min(t[ls].min, t[rs].min);
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
    return (qsum(ls, x, y) + qsum(rs, x, y));
}

int qmin(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return inf;
    if (x <= t[r].l && t[r].r <= y)
        return t[r].min;
    down(r);
    return min(qmin(ls, x, y), qmin(rs, x, y));
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
    res = (res + qsum(1, id[v], id[u]));
    return res;
}

int qminp(int u, int v)
{
    int res = inf;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res = min(res, qmin(1, id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if (u == v)
        return res;
    if (dep[u] < dep[v])
        swap(u, v);
    res = min(res, qmin(1, id[v] + 1, id[u]));
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
    t[r] = {x, y, 0, nw[x], nw[x]};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void dfs1(int u, int f)
{
    fa[u] = f, dep[u] = dep[f] + 1, sz[u] = 1;
    for (auto &[v, w] : e[u])
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

void dfs2(int u, int t, int w)
{
    top[u] = t;
    id[u] = ++cnt;
    nw[cnt] = w;
    if (!son[u])
        return;
    int hw = 0;
    for (auto &p : e[u])
    {
        if (p.v == son[u])
        {
            hw = p.w;
            break;
        }
    }
    dfs2(son[u], t, hw);
    for (auto &p : e[u])
    {
        int v = p.v;
        int wt = p.w;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v, wt);
    }
}

int find(int x)
{
    if (F[x] == x)
        return x;
    return F[x] = find(F[x]);
}

void krus()
{
    sort(E, E + m);
    for (int i = 1; i <= n; i++)
        F[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x = find(E[i].u);
        int y = find(E[i].v);
        if (x != y)
        {
            F[x] = y;
            e[E[i].u].push_back({E[i].v, E[i].w});
            e[E[i].v].push_back({E[i].u, E[i].w});
        }
    }
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 0; i < m; i++)
    {
        E[i].u = read();
        E[i].v = read();
        E[i].w = read();
    }
    krus();
    for (int i = 1; i <= n; i++)
    {
        if (!dep[i])
        {
            dfs1(i, 0);
            dfs2(i, i, inf);
        }
    }
    build(1, 1, n);
    int q = read();
    while (q--)
    {
        int x = read();
        int y = read();
        if (find(x) != find(y))
            cout << -1 << endl;
        else
            cout << qminp(x, y) << endl;
    }
    return 0;
}