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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<int> ans(n + 1);
    vector<set<int>> e(n + 1);
    vector<int> cnt(n + 1);
    while (m--)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            int u;
            cin >> u;
            cnt[u]++;
        }
        else if (c == '+')
        {
            int u, v;
            cin >> u >> v;
            ans[u] -= cnt[v];
            ans[v] -= cnt[u];
            e[u].insert(v);
            e[v].insert(u);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            ans[u] += cnt[v];
            ans[v] += cnt[u];
            e[u].erase(v);
            e[v].erase(u);
        }
    }
    for (int i = 1; i <= n; i++)
        for (auto &v : e[i])
            ans[i] += cnt[v];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}