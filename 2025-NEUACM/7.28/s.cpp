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
int a[N];
int dis[N];
int n, k;
int ans;

void dfs(int u, int fa)
{
    for (auto &v : e[u])
    {
        dfs(v, u);
        dis[u] = max(dis[u], dis[v] + 1);
    }
    if (dis[u] == k - 1 && fa > 1 && a[u] ^ 1)
    {
        ans++;
        dis[u] = -1;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    a[1] = read();
    if (a[1] != 1)
        ans++;
    for (int i = 2; i <= n; i++)
    {
        a[i] = read();
        e[a[i]].push_back(i);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}