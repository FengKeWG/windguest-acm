#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 10005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
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

struct node
{
    int v, w;
};

int n;
vector<node> e[MAXN];
int d1[MAXN], d2[MAXN], p1[MAXN], up[MAXN];
// d1：最长的子链，d2次长子链，p1最长的子链节点百年好是什么，up上面的最长的

int dfs_d(int u, int fa)
{
    d1[u] = 0;
    d2[u] = 0;
    for (auto &x : e[u])
    {
        int v = x.v, w = x.w;
        if (v == fa)
            continue;
        int d = dfs_d(v, u) + w;
        if (d >= d1[u])
        {
            d2[u] = d1[u];
            d1[u] = d;
            p1[u] = v;
        }
        else if (d > d2[u])
            d2[u] = d;
    }
    return d1[u];
}

void dfs_u(int u, int fa)
{
    for (auto &x : e[u])
    {
        int v = x.v, w = x.w;
        if (v == fa)
            continue;
        if (v == p1[u])
            up[v] = max(up[u], d2[u]) + w;
        else
            up[v] = max(up[u], d1[u]) + w;
        dfs_u(v, u);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs_d(1, 0);
    dfs_u(1, 0);
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, max(up[i], d1[i]));
    }
    cout << ans;
    return 0;
}