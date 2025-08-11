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

vector<int> e[N];
int d[N];
int p;
int fa[N];
int ans;
int s, t;

void dfs(int u, int f)
{
    if (d[u] > ans)
    {
        ans = d[u];
        p = u;
    }
    for (auto v : e[u])
    {
        if (v == f)
            continue;
        d[v] = d[u] + 1;
        fa[v] = u;
        dfs(v, u);
    }
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), k = read();
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        memset(d, -1, sizeof d);
        ans = -1;
        d[1] = 0;
        fa[1] = 0;
        dfs(1, 0);
        s = p;
        memset(d, -1, sizeof d);
        ans = -1;
        d[s] = 0;
        fa[s] = 0;
        dfs(s, 0);
        t = p;
        vector<int> p;
        for (int v = t; v; v = fa[v])
            p.push_back(v);
        reverse(p.begin(), p.end());
        for (auto &x : p)
            cout << x << ' ';
    }
    return 0;
}