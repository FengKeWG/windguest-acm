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

/*
树链剖分
重儿子: 父结点的所有儿子中子树结点数目最多的结点
轻儿子: 父结点中除重儿子以外的儿子
重边: 父结点和重儿子连成的边
轻边: 父结点和轻儿子连成的边
重链: 由多条重边连接而成的路径
1. 整棵树会被剖分成若干条重链
2. 轻儿子一定是每条重链的顶点
3. 任意一条路径被切分成不超过 logn 条链,
*/

int fa[N], dep[N], son[N], sz[N], top[N];
// u的父节点；u的深度；u的重儿子；u的子树节点数；u所在重链的顶点

void dfs1(int u, int fat)
{
    fa[u] = fat;
    dep[u] = dep[fat] + 1;
    sz[u] = 1;
    for (auto &v : e[u])
    {
        if (v == fat)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v])
            son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u])
        return; // 没有重儿子（叶子）
    dfs2(son[u], t);
    for (auto &v : e[u])
    {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}