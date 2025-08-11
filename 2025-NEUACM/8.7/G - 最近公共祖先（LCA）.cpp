#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

vector<int> e[N];
int dep[N], fa[N][20];
int n, m, r;

void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto &v : e[u])
        if (v != f)
            dfs(v, u);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), r = read();
    for (int i = 1; i < n; i++)
    {
        int x = read(), y = read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(r, 0);
    while (m--)
    {
        int x = read(), y = read();
        cout << lca(x, y) << endl;
    }
    return 0;
}