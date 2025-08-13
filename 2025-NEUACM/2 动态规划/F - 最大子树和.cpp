#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 16005
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

int n, ans;
int a[N];
vector<int> e[N];
int f[N];

void dfs(int u, int fa)
{
    f[u] = a[u];
    for (auto &v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        if (f[v] > 0)
            f[u] += f[v];
    }
    ans = max(ans, f[u]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = a[1];
    dfs(1, 0);
    cout << ans;
    return 0;
}