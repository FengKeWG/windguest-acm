#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 100005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
#define mid (l + r >> 1)
#define ls(x) tr[x].l
#define rs(x) tr[x].r
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

int n, m, ans[N];
vector<int> g[N];
int fa[N][20], dep[N];
int root[N], tot;
struct node
{
    int l, r, sum, typ;
} t[N * 50];

void dfs(int x, int f)
{
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i <= 18; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int y : g[x])
        if (y != f)
            dfs(y, x);
}

int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 18; ~i; i--)
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if (x == y)
        return y;
    for (int i = 18; ~i; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void up(int u)
{
    if (t[t[u].l].sum >= t[t[u].r].sum)
    {
        t[u].sum = t[t[u].l].sum;
        t[u].typ = t[t[u].l].typ;
    }
    else
    {
        t[u].sum = t[t[u].r].sum;
        t[u].typ = t[t[u].r].typ;
    }
}

void change(int &u, int l, int r, int p, int k)
{
    if (!u)
        u = ++tot;
    if (l == r)
    {
        t[u].sum += k;
        t[u].typ = p;
        return;
    }
    if (p <= mid)
        change(t[u].l, l, mid, p, k);
    else
        change(t[u].r, mid + 1, r, p, k);
    up(u);
}

int merge(int x, int y, int l, int r)
{
    if (!x || !y)
        return x + y;
    if (l == r)
    {
        t[x].sum += t[y].sum;
        return x;
    }
    t[x].l = merge(t[x].l, t[y].l, l, mid);
    t[x].r = merge(t[x].r, t[y].r, mid + 1, r);
    up(x);
    return x;
}

void dfs2(int x, int f)
{
    for (int y : g[x])
    {
        if (y == f)
            continue;
        dfs2(y, x);
        root[x] = merge(root[x], root[y], 1, N);
    }
    ans[x] = t[root[x]].sum ? t[root[x]].typ : 0;
}

signed main()
{
    n = read(), m = read();
    for (int i = 1, x, y; i < n; i++)
    {
        x = read(), y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1, x, y, z; i <= m; i++)
    {
        x = read(), y = read(), z = read();
        change(root[x], 1, N, z, 1);
        change(root[y], 1, N, z, 1);
        int t = lca(x, y);
        change(root[t], 1, N, z, -1);
        change(root[fa[t][0]], 1, N, z, -1);
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}