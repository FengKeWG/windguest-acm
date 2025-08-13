#include <bits/stdc++.h>
// #define int long long
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
    int lc, rc, sum, tag;
} t[N << 2];

vector<int> e[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N];
int cnt;
int k;
int n, m, r, p;

void cal(Node &t, int c)
{
    t.sum = t.r - t.l;
    t.lc = t.rc = c;
    t.tag = c;
}

void down(int r)
{
    if (t[r].tag)
    {
        cal(t[ls], t[r].tag);
        cal(t[rs], t[r].tag);
        t[r].tag = 0;
    }
}

void up(int r)
{
    t[r].sum = t[ls].sum + t[rs].sum;
    if (t[ls].rc == t[rs].lc)
        t[r].sum++;
    t[r].lc = t[ls].lc;
    t[r].rc = t[rs].rc;
}

int qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (x <= t[r].l && t[r].r <= y)
        return t[r].sum;
    down(r);
    int res = 0;
    int m = mid;
    if (x <= m)
        res += qsum(ls, x, y);
    if (y > m)
        res += qsum(rs, x, y);
    if (x <= m && y > m && t[ls].rc == t[rs].lc)
        res++;
    return res;
}

int qcolor(int r, int pos)
{
    if (t[r].l == t[r].r)
        return t[r].lc;
    down(r);
    if (pos <= t[ls].r)
        return qcolor(ls, pos);
    else
        return qcolor(rs, pos);
}

void upd(int r, int x, int y, int c)
{
    if (t[r].l > y || t[r].r < x)
        return;
    if (x <= t[r].l && t[r].r <= y)
    {
        cal(t[r], c);
        return;
    }
    down(r);
    upd(ls, x, y, c);
    upd(rs, x, y, c);
    up(r);
}

void updp(int u, int v)
{
    int c = ++k;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        upd(1, id[top[u]], id[u], c);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    upd(1, id[v], id[u], c);
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
            res++;
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    res += qsum(1, id[v], id[u]);
    return res;
}

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y;
    t[r].tag = 0;
    if (x == y)
    {
        t[r].lc = t[r].rc = ++k;
        t[r].sum = 0;
        return;
    }
    int m = mid;
    build(ls, x, m);
    build(rs, m + 1, y);
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
    top[u] = t, id[u] = ++cnt;
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
    int T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
            fa[i] = dep[i] = son[i] = sz[i] = top[i] = id[i] = 0;
        }
        cnt = k = 0;
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs1(1, 0);
        dfs2(1, 1);
        build(1, 1, n);
        while (m--)
        {
            int op = read(), x = read(), y = read();
            if (op == 1)
                updp(x, y);
            else
                cout << qsump(x, y) << endl;
        }
    }
    return 0;
}