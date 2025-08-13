#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 205
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

int n, m;

struct node2
{
    int x, y;
} a[N];

struct node
{
    int v;
    double w;
};
vector<node> e[N];

double cal(node2 a, node2 b)
{
    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
}

bool ban[N][N];
bool vis[N];
double dis[N];
int pre[N];
vector<pii> b;

void dij(int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    memset(vis, 0, sizeof vis);
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
            if (ban[u][v])
                continue;
            // cout << dis[v] << ' ' << dis[u] << ' ' << w << endl;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                // cout << dis[v] << endl;
                pre[v] = u;
                q.push({-dis[v], v});
            }
        }
    }
}

double ans = inf;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i].x = read(), a[i].y = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        double d = cal(a[u], a[v]);
        e[u].push_back({v, d});
        e[v].push_back({u, d});
    }
    dij(1);
    // cout << dis[n] << endl;
    for (int v = n; pre[v]; v = pre[v])
    {
        b.push_back({pre[v], v});
        // cout << pre[v] << ' ' << v << endl;
    }
    for (auto &[u, v] : b)
    {
        ban[u][v] = 1;
        ban[v][u] = 1;
        dij(1);
        ans = min(ans, dis[n]);
        ban[u][v] = 0;
        ban[v][u] = 0;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}