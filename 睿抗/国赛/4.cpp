#include <bits/stdc++.h>
#define int long long
#define inf LLONG_MAX / 2
#define endl '\n'
#define pii pair<int, int>
#define N 1005
using namespace std;

int C[N];
struct node
{
    int v, w;
};
vector<node> e[N];
int st, ed;
bool vis[N];
int d[N];
struct node2
{
    int v, i;
    bool operator<(const node2 &t) const
    {
        return v < t.v;
    }
} a[N];
int n, m;

void dij(int s, int k)
{
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    memset(vis, 0, sizeof vis);
    priority_queue<pii> q;
    q.push({0, s});
    d[s] = 0;
    while (q.size())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &[v, w] : e[u])
        {
            if (C[v] > k)
                continue;
            if (d[v] >= d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> C[i];
        a[i].v = C[i];
        a[i].i = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    sort(a + 1, a + 1 + n);
    cin >> st >> ed;
    if (st == ed)
    {
        cout << 0 << ' ' << 0;
        return 0;
    }
    int ans = inf;
    for (auto &[v, w] : e[st])
    {
        if (v == ed)
            ans = min(ans, w);
    }
    if (ans != inf)
    {
        cout << 0 << ' ' << ans;
        return 0;
    }
    int i = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[i].i == st || a[i].i == ed)
            continue;
        dij(st, a[i].v);
        if (d[ed] != inf)
            break;
    }
    cout << a[i].v << ' ' << d[ed] << endl;
    return 0;
}