#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 105
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
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

int n, m, ans;
bool vis[MAXN][MAXN];

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
            if (x + dx >= 1 && x + dx <= m && y + dy >= 1 && y + dy <= n)
                if (!vis[x + dx][y + dy])
                    dfs(x + dx, y + dy);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            vis[j + 1][i] = s[j] == 'W' ? 0 : 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[j][i])
            {
                ans++;
                dfs(j, i);
            }
    cout << ans;
    return 0;
}