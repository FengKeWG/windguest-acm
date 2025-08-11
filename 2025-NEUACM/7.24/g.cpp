#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 305
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
int n, W;
int f[N][N];

void dfs(int u)
{
    for (auto &v : e[u])
        dfs(v);
    for (auto &v : e[u])
        for (int j = W + 1; j > 0; j--)
            for (int k = 0; k < j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), W = read();
    for (int i = 1; i <= n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(i);
        f[i][1] = v;
    }
    dfs(0);
    cout << f[0][W + 1];
    return 0;
}