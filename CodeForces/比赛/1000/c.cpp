#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

vector<vector<int>> g;
vector<bool> vis;
vector<int> cnt;

void dfs(int u)
{
    vis[u] = true;
    for (auto &v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t = read();
    while (t--)
    {
        int ans = 0;
        int n = read();
        vis.assign(n + 1, false);
        g.assign(n + 1, vector<int>());
        cnt.assign(n + 1, 0);
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            g[u].push_back(v);
            g[v].push_back(u);
            cnt[u]++, cnt[v]++;
        }
        for (int j = 1; j <= 2; j++)
        {
            int maxn = 0;
            int maxpos;
            for (int i = 1; i <= n; i++)
            {
                if (cnt[i] >= maxn && !vis[i])
                {
                    maxn = cnt[i];
                    maxpos = i;
                }
            }
            // cout << maxpos << endl;
            for (auto &x : g[maxpos])
            {
                cnt[x]--;
            }
            vis[maxpos] = true;
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