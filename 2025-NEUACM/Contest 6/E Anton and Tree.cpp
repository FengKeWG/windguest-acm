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

int a[N];
vector<int> e[N];
bool vis[N];
int fa[N];
int f[N][2];
int sz1[N], sz0[N];

void dfs(int u, int f)
{
    for (auto &v : e[u])
    {
        if (v == f)
            continue;
        if (a[v] == 1)
            sz1[u]++;
        else if (a[v] == 0)
            sz0[u]++;
        dfs(v, u);
    }
}

void dfs2(int u, int fat)
{
    int c0 = 0, c1 = 0;
    int min0 = inf, min1 = inf;
    int m0 = inf, m1 = inf;
    for (auto &v : e[u])
    {
        if (v == fat)
            continue;
        dfs2(v, u);
        min0 = min(min0, f[v][0]);
        min1 = min(min1, f[v][1]);
        c0 += f[v][0];
        c1 += f[v][1];
    }
    for (auto &v : e[u])
    {
        if (v == fat)
            continue;
        m0 = min(m0, c1 - f[v][1] + f[v][0] + 1);
        m1 = min(m1, c0 - f[v][0] + f[v][1] + 1);
    }
    //  cout << u << " " << c0 << " " << c1 << endl;
    if (a[u] == 0)
    {
        f[u][0] = min(c0, c1 + 2);
        f[u][1] = min(c0 + 1, c1 + 1);
        f[u][1] = min(f[u][1], m0);
        f[u][1] = min(f[u][1], c1 - sz0[u] + 1);
    }
    else
    {
        f[u][1] = min(c0 + 2, c1);
        f[u][0] = min(c0 + 1, c1 + 1);
        f[u][0] = min(f[u][0], m1);
        f[u][0] = min(f[u][0], c0 - sz1[u] + 1);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        f[i][a[i]] == 0;
        f[i][1 - a[i]] == inf;
    }
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    // cout << f[3][0] << " " << f[3][1] << endl;
    // cout << f[2][0] << " " << f[2][1] << endl;
    // cout << f[1][0] << " " << f[1][1] << endl;
    cout << min(f[1][0], f[1][1]) << endl;
    return 0;
}