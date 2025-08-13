#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define inf LLONG_MAX
#define N 15
using namespace std;

int T;
int n, m;
vector<int> e[N];
vector<int> g[N];
bool vis[N];
set<int> ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        ans.clear();
        for (int i = 1; i <= n; i++)
            e[i].clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int k = 11;
        bool can = 1;
        memset(vis, 0, sizeof vis);
        int tot = 0;
        for (int j = 0; j < n; j++)
        {
            if (k >> j & 1)
            {
                tot++;
            }
            else
            {
                cout << j << endl;
                int u = n - j;
                vis[u] = 1;
            }
        }
        // if (tot == 2)
        // {
        //     ans.insert(2);
        //     continue;
        // }
        for (int i = 1; i <= n; i++)
            g[i].clear();
        int M = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i])
                cout << i << endl;
        for (int u = 1; u <= n; u++)
        {
            if (vis[u])
                continue;
            int cnt = e[u].size();
            for (auto &v : e[u])
            {
                if (vis[v])
                    cnt--;
                else
                {
                    M++;
                    g[u].push_back(v);
                }
            }
            if (cnt <= 0)
            {
                cout << u << " ";
                can = 0;
                break;
            }
        }
        if (!can)
            continue;
        M /= 2;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            if (M - g[i].size() + 1 != tot - 1)
            {
                can = 0;
                break;
            }
            for (auto &v : g[i])
            {
                if (tot != 2 && g[v].size() == 1)
                {
                    can = 0;
                    break;
                }
                if (tot == 2 && g[v].size() < 0)
                {
                    can = 0;
                    break;
                }
            }
            if (!can)
                break;
        }
        if (!can)
            continue;
        ans.insert(tot);
    }
    if (ans.size() == 1)
        cout << *ans.begin() << " " << 0 << endl;
    else if (ans.size() == 0)
        cout << 0 << " " << 0 << endl;
    else
        cout << *ans.rbegin() << ' ' << *(prev(ans.rbegin())) << endl;
    return 0;
}