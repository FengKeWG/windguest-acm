#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 505
#define INF LLONG_MAX
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

struct node2
{
    int w, maxw, dis, cnt, vis, pre;
};

int n, m, s, d;
vector<vector<node>> e;
vector<node2> a;

void dij(int s)
{
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    a[s].dis = 0;
    a[s].maxw = a[s].w;
    a[s].cnt = 1;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int u = t.second;
        if (a[u].vis)
            continue;
        a[u].vis = 1;
        for (auto &x : e[u])
        {
            int v = x.v, w = x.w;
            if (a[v].dis > a[u].dis + w)
            {
                a[v].dis = a[u].dis + w;
                a[v].maxw = a[u].maxw + a[v].w;
                a[v].cnt = a[u].cnt;
                a[v].pre = u;
                q.push({-a[v].dis, v});
            }
            else if (a[v].dis == a[u].dis + w)
            {
                a[v].cnt += a[u].cnt;
                if (a[v].maxw < a[u].maxw + a[v].w)
                {
                    a[v].maxw = a[u].maxw + a[v].w;
                    a[v].pre = u;
                }
                q.push({-a[v].dis, v});
            }
        }
    }
}

void out(int ed)
{
    vector<int> ans;
    for (int v = ed; v != -1; v = a[v].pre)
        ans.push_back(v);
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        cout << x << " ";
    cout << endl;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m >> s >> d)
    {
        e.assign(n, vector<node>());
        a.assign(n, node2());
        for (auto &x : a)
        {
            cin >> x.w;
            x.dis = INF;
            x.cnt = 0;
            x.maxw = 0;
            x.pre = -1;
        }
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        dij(s);
        cout << a[d].cnt << " " << a[d].maxw << endl;
        out(d);
    }

    return 0;
}