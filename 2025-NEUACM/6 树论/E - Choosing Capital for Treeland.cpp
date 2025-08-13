#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
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

struct node
{
    int v, w;
};
vector<node> e[N];
int f[N];

void dfs(int u, int fat)
{
    for (auto &[v, w] : e[u])
    {
        if (v == fat)
            continue;
        dfs(v, u);
        f[u] += f[v] + w;
    }
}

void dfs2(int u, int fat)
{
    for (auto &[v, w] : e[u])
    {
        if (v == fat)
            continue;
        f[v] = f[u] + (w ? -1 : 1);
        dfs2(v, u);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 2; i <= n; i++)
    {
        int u = read(), v = read();
        e[u].push_back({v, 0});
        e[v].push_back({u, 1});
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << endl;
    dfs2(1, 0);
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << endl;
    int ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans, f[i]);
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (f[i] == ans)
            cout << i << ' ';
    return 0;
}