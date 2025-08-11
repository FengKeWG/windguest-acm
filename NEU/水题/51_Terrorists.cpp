#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
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
    bool operator>(const node &x) const
    {
        return w > x.w;
    }
};

int n, m, q;
vector<int> dis;
vector<vector<node>> e;
unordered_map<int, vector<int>> ans;

void dij(int s)
{
    dis.assign(n + 1, LLONG_MAX);
    dis[s] = 0;
    priority_queue<node, vector<node>, greater<node>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        int u = q.top().v;
        int w = q.top().w;
        q.pop();

        if (w > dis[u])
            continue;

        for (auto &v : e[u])
        {
            if (dis[v.v] > dis[u] + v.w)
            {
                dis[v.v] = dis[u] + v.w;
                q.push({v.v, v.w});
            }
        }
    }
    ans[s] = dis;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int _ = read();
    for (int j = 1; j <= _; j++)
    {
        cout << "Case " << j << ":\n";
        n = read(), m = read(), q = read();

        e.clear();
        e.resize(n + 1);
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read(), w = read();
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        while (q--)
        {
            int x = read(), y = read();
            if (!ans[x].empty())
            {
                cout << ans[x][y] << endl;
                continue;
            }
            if (!ans[y].empty())
            {
                cout << ans[y][x] << endl;
                continue;
            }
            dij(x);
            cout << ans[x][y] << endl;
        }
    }

    return 0;
}