#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid (t[r].l + t[r].r >> 1)
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

struct node
{
    int l, r;
    int sum;
    int mul, add;
    node operator+(const node &t) const
    {
        node res;
        res.l = l, res.r = t.r;
        res.sum = sum + t.sum;
        res.mul = 1, res.add = 0;
        return res;
    }
} t[N << 2];

vector<int> e[N];
int w[N];
int fa[N], dep[N], son[N], sz[N], top[N], id[N], nw[N];
int cnt;
int n, m, p;

void cal(node &t, int mul, int add)
{
    t.sum = t.sum * mul + (t.r - t.l + 1) * add;
    t.mul *= mul;
    t.add = t.add * mul + add;
}

void down(int r)
{
    if (t[r].add == 0 && t[r].mul == 1)
        return;
    cal(t[ls], t[r].mul, t[r].add);
    cal(t[rs], t[r].mul, t[r].add);
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

void upd(int r, int x, int y, int mul, int add)
{
    if (t[r].l > y || t[r].r < x)
        return;
    if (x <= t[r].l && t[r].r <= y)
    {
        cal(t[r], mul, add);
        return;
    }
    down(r);
    upd(ls, x, y, mul, add);
    upd(rs, x, y, mul, add);
    t[r] = t[ls] + t[rs];
}

void updp(int u, int v, int mul, int add)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        upd(1, id[top[u]], id[u], mul, add);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u, v);
    upd(1, id[v], id[u], mul, add);
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

void updt(int u, int mul, int add)
{
    upd(1, id[u], id[u] + sz[u] - 1, mul, add);
}

int qsumt(int u)
{
    return qsum(1, id[u], id[u] + sz[u] - 1);
}

void build(int r, int x, int y)
{
    t[r] = {x, y, nw[x], 1, 0};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    t[r] = t[ls] + t[rs];
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
    // cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 2; i <= n; i++)
    {
        int p = read();
        e[i].push_back(p);
        e[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        w[i] = read();
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    m = read();
    while (m--)
    {
        string op;
        int x;
        cin >> op >> x;
        if (op[0] == 'p')
            updt(x, -1, 1);
        else
            cout << qsumt(x) << endl;
    }
    return 0;
}