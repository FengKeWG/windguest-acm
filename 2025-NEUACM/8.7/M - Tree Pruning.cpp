#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
#define M 100005
#define mod 998244353
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

int dep[N], k[N], sz[N], z[N];
int mx[N];
int dmx;
vector<int> e[N];

void dfs(int u, int f)
{
    if (u != 1)
        dep[u] = dep[f] + 1;
    dmx = max(dmx, dep[u]);
    sz[u] = 1;
    if (e[u].size() == 1 && u != 1)
        mx[u] = dep[u];
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        dfs(v, u);
        k[dep[u]] += sz[v];
        sz[u] += sz[v];
        mx[u] = max(mx[u], mx[v]);
    }
    if (u != 1)
        z[mx[u] + 1]++;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
            k[i] = 0;
            sz[i] = 0;
            z[i] = 0;
            mx[i] = 0;
        }
        dmx = 0;
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dep[1] = 0;
        dfs(1, -1);
        for (int i = 1; i <= dmx; i++)
            z[i] += z[i - 1];
        for (int i = 1; i <= dmx; i++)
            k[i] += z[i];
        int ans = inf;
        for (int i = 1; i <= dmx; i++)
            ans = min(ans, k[i]);
        cout << ans << endl;
    }
    return 0;
}
