#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
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
    int l, r, add, sum, mul;
} t[N * 4];

vector<int> e[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N];
int cnt;
int n, m;

void calc(Node &t, int add, int mul)
{
    t.sum = (t.sum * mul + (t.r - t.l + 1) * add);
    t.mul = t.mul * mul;
    t.add = t.add * mul + add;
}

void up(int r)
{
    t[r].sum = (t[ls].sum + t[rs].sum);
}

void down(int r)
{
    calc(t[ls], t[r].add, t[r].mul);
    calc(t[rs], t[r].add, t[r].mul);
    t[r].add = 0;
    t[r].mul = 1;
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

void upd(int r, int x, int y, int add, int mul)
{
    if (t[r].l > y || t[r].r < x)
        return;
    if (x <= t[r].l && t[r].r <= y)
    {
        calc(t[r], add, mul);
        return;
    }
    down(r);
    upd(ls, x, y, add, mul);
    upd(rs, x, y, add, mul);
    up(r);
}

void updp(int u, int v, int add, int mul)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        upd(1, id[top[u]], id[u], add, mul);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    upd(1, id[v], id[u], add, mul);
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

void updt(int u, int add, int mul)
{
    upd(1, id[u], id[u] + sz[u] - 1, add, mul);
}

int qsumt(int u)
{
    return qsum(1, id[u], id[u] + sz[u] - 1);
}

void build(int r, int x, int y)
{
    t[r] = {x, y, 0, 0, 1};
    if (x == y)
        return;
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
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    m = read();
    while (m--)
    {
        int c = read(), v = read();
        if (c == 1)
            updt(v, 1, 1);
        else if (c == 2)
            updp(1, v, 0, 0);
        else if (qsump(v, v))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}