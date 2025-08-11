#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
int n;

void dfs(int u, int fat)
{
    dep[u] = dep[fat] + 1;
    fa[u][0] = fat;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto &v : e[u])
        if (v != fat)
            dfs(v, u);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);               // 保证u在下面，让u往上跳
    for (int i = 19; i >= 0; i--) // 跳到同一层
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--) // 一起跳
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

// 树上最短路：dist(u,v)=dist(u,LCA(u,v))+dist(v,LCA(u,v))
// 即：dist(u,v)=dep[u]+dep[v]−2⋅dep[LCA(u,v)]

int dis(int u, int v)
{
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}