#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

int n, res, cnt, sum[N], fa[N], sz[N];
bool vis[N];
vector<int> e[N];

void dfs(int u, int f)
{
    fa[u] = f;
    sz[u] = 1;
    sum[u] = vis[u];
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        dfs(v, u);
        sum[u] += sum[v];
        sz[u] += sz[v];
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read();
        cnt = 0;
        for (int i = 1; i <= n; i++)
            e[i].clear(), vis[i] = 0;
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (e[i].size() > 1)
                continue;
            cnt++;
            vis[i] = 1;
            for (int j : e[i])
                vis[j] = 1;
        }
        res = cnt * (n - cnt);
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
        {
            int tot1 = 0, tot2 = 0;
            if (e[i].size() == 1)
                continue;
            for (int j : e[i])
            {
                if (j == fa[i] || vis[j] == 0 || e[j].size() == 1)
                    continue;
                tot1 += sz[j] - sum[j];
            }
            if (i != 1 && vis[fa[i]] && e[fa[i]].size() > 1)
                tot2 += (n - sz[i]) - (sum[1] - sum[i]);
            res += tot1 + tot2;
        }
        cout << res << endl;
    }
    return 0;
}
