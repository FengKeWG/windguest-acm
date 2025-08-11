#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

int n, m;
int a[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool vis[N][N];

bool dfs(int x, int y, int p)
{
    if (x == n)
        return 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            if (!vis[nx][ny] && a[nx][ny] <= p)
                if (dfs(nx, ny, p))
                    return 1;
        }
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    int l = -1, r = 1005;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        memset(vis, 0, sizeof(vis));
        if (dfs(1, 1, mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
    return 0;
}