#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

int n, m;
int ans;
vector<vector<int>> e;
vector<bool> vis;

void dfs(int u)
{
    vis[u] = 1;
    for (auto &v : e[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (cin >> n >> m)
    {
        ans = 0;
        e.resize(n + 1);
        vis.resize(n + 1);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}