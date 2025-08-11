#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int n, m;
struct node
{
    int v, w;
};
vector<node> e[N], ne[N];
int dis[N];
bool vis[N];
int ans[N];

void dij(int s)
{
    for (int i = 0; i <= n; i++)
        dis[i] = inf;
    priority_queue<pii> q;
    q.push({0, s});
    dis[s] = 0;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v, w] : e[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

void dij2()
{
    for (int i = 0; i <= n; i++)
        ans[i] = inf;
    priority_queue<pii> q;
    for (int v = 1; v <= n; v++)
    {
        if (dis[v] != inf)
        {
            ans[v] = dis[v];
            q.push({-ans[v], v});
        }
    }
    memset(vis, 0, sizeof vis);
    while (q.size())
    {
        auto [d, u] = q.top();
        d = -d;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v, w] : ne[u])
        {
            if (ans[v] > d + w)
            {
                ans[v] = d + w;
                q.push({-(d + w), v});
            }
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 0; i < m; ++i)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        ne[v].push_back({u, w});
    }
    dij(1);
    dij2();
    for (int i = 2; i <= n; i++)
        cout << (ans[i] == inf ? -1 : ans[i]) << ' ';
    return 0;
}