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
    int add;
    int sum;
    int lc, rc;
} t[N * 4];
int col[N], rid[N];
vector<int> e[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N];
int cnt;
int n, r, q;

void cal(int r, int color)
{
    t[r].sum = 1;
    t[r].add = color;
    t[r].lc = t[r].rc = color;
}

void up(int r)
{
    t[r].sum = t[ls].sum + t[rs].sum - (t[ls].rc == t[rs].lc);
    t[r].lc = t[ls].lc;
    t[r].rc = t[rs].rc;
}

void down(int r)
{
    if (t[r].add != -1)
    {
        cal(ls, t[r].add);
        cal(rs, t[r].add);
        t[r].add = -1;
    }
}

struct node
{
    int lcol, rcol, seg;
};

node query(int r, int x, int y)
{
    if (x <= t[r].l && t[r].r <= y)
        return {t[r].lc, t[r].rc, t[r].sum};
    if (t[r].r < x || t[r].l > y)
        return {-1, -1, 0};
    down(r);
    node a = query(ls, x, y);
    node b = query(rs, x, y);
    if (a.seg == 0)
        return b;
    if (b.seg == 0)
        return a;
    node res;
    res.lcol = a.lcol;
    res.rcol = b.rcol;
    res.seg = a.seg + b.seg - (a.rcol == b.lcol);
    return res;
}

int qsum(int r, int x, int y)
{
    return query(r, x, y).seg;
}

void upd(int r, int x, int y, int color)
{
    if (t[r].r < x || t[r].l > y)
        return;
    if (x <= t[r].l && t[r].r <= y)
    {
        cal(r, color);
        return;
    }
    down(r);
    upd(ls, x, y, color);
    upd(rs, x, y, color);
    up(r);
}

int qcolor(int r, int pos)
{
    if (t[r].l == t[r].r)
        return t[r].lc;
    down(r);
    if (pos <= mid)
        return qcolor(ls, pos);
    return qcolor(rs, pos);
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
        if (fa[top[u]] && qcolor(1, id[top[u]]) == qcolor(1, id[fa[top[u]]]))
            --res;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    res += qsum(1, id[u], id[v]);
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
    t[r].l = x;
    t[r].r = y;
    t[r].add = -1;
    t[r].sum = 0;
    t[r].lc = t[r].rc = 0;
    if (x == y)
    {
        int node = rid[x];
        t[r].lc = t[r].rc = col[node];
        t[r].sum = 1;
        return;
    }
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
    top[u] = t;
    id[u] = ++cnt;
    rid[cnt] = u;
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
    // cin.tie(0)->sync_with_stdio(0);
    n = read(), q = read();
    for (int i = 1; i <= n; ++i)
        col[i] = read();
    for (int i = 1; i < n; ++i)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    r = 1;
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    while (q--)
    {
        char op;
        cin >> op;
        if (op == 'C')
        {
            int a = read(), b = read(), c = read();
            updp(a, b, c);
        }
        else
        {
            int a = read(), b = read();
            cout << qsump(a, b) << endl;
        }
    }
    return 0;
}