#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define lson (r << 1)
// #define rson (r << 1 | 1)
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
int fa[N], dep[N], son[N], sz[N], top[N], id[N];
int len[N], rnk[N];
int cnt;
int n, q;

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
    rnk[cnt] = u;
    if (!son[u])
    {
        len[u] = 1;
        return;
    }
    dfs2(son[u], t);
    len[u] = len[son[u]] + 1;
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
    n = read(), q = read();
    for (int i = 2; i <= n; i++)
    {
        int u = read();
        e[u].push_back(i);
        e[i].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    while (q--)
    {
        int a = read();
        int l = id[a], r = id[a] + len[a] - 1;
        int ans = l;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (2 * sz[rnk[mid]] > sz[a])
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
        }
        cout << rnk[ans] << endl;
    }
    return 0;
}