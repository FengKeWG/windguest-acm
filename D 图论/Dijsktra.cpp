#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define inf 0x3f3f3f3f3f3f3f3fLL
#define pii pair<int, int>
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

vector<node> e[N];
int dis[N];
bool vis[N];

void dij(int s)
{
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

signed main()
{
    int n = read(), m = read(), s = read();
    memset(dis, inf, sizeof(dis));
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
    }
    dij(s);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << ' ';
    }
    return 0;
}