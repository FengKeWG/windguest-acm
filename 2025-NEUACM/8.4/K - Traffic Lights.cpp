#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 5005
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

vector<int> e[N];
int f[2][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), m = read();
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i <= m; i++)
        {
            int u = read(), v = read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = inf;
        f[0][1] = 0;
        int t = 0;
        for (int i = 0; i <= 3 * n; i++)
        {
            int k = i % 2;
            for (int u = 1; u <= n; u++)
                f[(k + 1) % 2][u] = inf;
            for (int u = 1; u <= n; u++)
            {
                f[(k + 1) % 2][u] = min(f[(k + 1) % 2][u], f[k][u] + 1);
                f[(k + 1) % 2][e[u][i % e[u].size()]] = min(f[(k + 1) % 2][e[u][i % e[u].size()]], f[k][u]);
            }
            if (f[k][n] != inf)
            {
                t = i;
                break;
            }
        }
        cout << t << ' ' << f[t % 2][n] << endl;
    }
    return 0;
}