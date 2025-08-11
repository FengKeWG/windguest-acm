#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
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

int n, m, k;
vector<int> e[N];
bool vis[N];
vector<int> ans;

void dfs(int u, int d)
{
    vis[u] = 1;
    if (d == 2)
        return;
    for (auto &v : e[u])
        dfs(v, d + 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans.push_back(i);
            dfs(i, 0);
        }
    }
    cout << ans.size() << endl;
    for (auto &x : ans)
        cout << x << ' ';
    return 0;
}