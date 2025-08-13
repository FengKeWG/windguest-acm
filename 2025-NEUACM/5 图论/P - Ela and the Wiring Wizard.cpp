#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 505
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX / 2
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

struct edge
{
    int u, v, w;
} e[N * N];
int n, m;
int dis[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = inf * (i != j);
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read(), w = read();
            e[i] = {u, v, w};
            dis[u][v] = dis[v][u] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        int ans = inf;
        for (int i = 1; i <= m; i++)
        {
            int u = e[i].u, v = e[i].v, cur = min(dis[u][1] + dis[v][n], dis[v][1] + dis[u][n]);
            for (int k = 1; k <= n; k++)
                cur = min(cur, min(dis[u][k], dis[v][k]) + 1 + dis[k][1] + dis[k][n]);
            ans = min(ans, (cur + 1) * e[i].w);
        }
        cout << ans << endl;
    }
    return 0;
}