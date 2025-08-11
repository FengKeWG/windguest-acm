#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 3005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
#define int128 __int128
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
vector<node> e[N];
int a[N];
int n, m;
int f[N], g[N];

void dfs(int u)
{
    for (auto &x : e[u])
    {
        int v = x.v, w = x.w;
        vector<int> b;
        dfs(v);
        if (f[v] - w >= 0)
        {
            f[u] += f[v] - w;
            g[u] += g[v];
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n - m; i++)
    {
        int k = read();
        while (k--)
        {
            int v = read(), w = read();
            e[i].push_back({v, w});
        }
    }
    for (int i = n - m + 1; i <= n; i++)
    {
        a[i] = read();
        f[i] = a[i];
        g[i] = 1;
    }
    dfs(1);
    cout << g[1];
    return 0;
}