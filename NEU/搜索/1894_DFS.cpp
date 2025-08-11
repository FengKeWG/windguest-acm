#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

int n;
vector<vector<int>> e;

struct node
{
    int d, f;
};

int t = 0;
vector<node> ans;
vector<bool> vis;

void dfs(int u)
{
    vis[u] = true;
    ans[u].d = ++t;
    for (auto &v : e[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    ans[u].f = ++t;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    e.resize(n + 1);
    ans.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, k, v;
        cin >> u >> k;
        while (k--)
        {
            cin >> v;
            e[u].push_back(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << ans[i].d << " " << ans[i].f << endl;
    }
    return 0;
}