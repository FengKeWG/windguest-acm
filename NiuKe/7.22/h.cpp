#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, x, y, k, u, v, l, r, len, cnt, lg[5000010], dis[1000010];
ll vis[1000010], dep[1000010], head[1000010], f[1000010][25];

struct wang
{
    ll to, next;
} e[2000010];

inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ '0');
        c = getchar();
    }
    return x * f;
}

inline void add(ll x, ll y)
{
    e[++cnt].next = head[x];
    e[cnt].to = y;
    head[x] = cnt;
}

inline void dfs(ll x, ll fa)
{
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;
    for (int i = 1; i < 23; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if (y == fa)
            continue;
        dfs(y, x);
    }
}

inline ll get(ll x)
{
    if (vis[x])
        return x;
    for (int i = 22; i >= 0; i--)
        if (!vis[f[x][i]] && f[x][i] >= 1)
        {
            x = f[x][i];
        }
    return f[x][0];
}

inline ll getf(ll x, ll len)
{
    for (int i = 22; i >= 0; i--)
        if (dep[f[x][i]] + len >= dep[x])
            x = f[x][i];
    return x;
}

int main()
{
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= 5000000; i++)
        lg[i] = lg[i >> 1] + 1;
    n = read();
    k = read();
    for (int i = 2; i <= n; i++)
    {
        x = read();
        add(x, i);
        add(i, x);
    }
    dfs(1, 0);
    dis[1] = 1;
    vis[1] = 1;
    for (int i = 1; i <= k; i++)
    {
        v = u = read();
        l = read();
        r = read();
        if (vis[v])
        {
            printf("%lld\n", l);
            return 0;
        }
        x = get(u);
        len = max(0ll, dep[u] - dep[x] - (r - l + 1));
        u = getf(u, len);
        for (int i = 1; i <= r - l + 1; i++)
        {
            dis[u] = l + dep[u] - dep[x] - 1;
            vis[u] = 1;
            u = f[u][0];
        }
        if (vis[v])
        {
            printf("%lld\n", dis[v]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}