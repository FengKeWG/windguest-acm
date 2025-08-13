#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 21
#define M 100005
#define mod 100000007
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

int n;
int a[N][N], f[N][1 << N];
bool vis[N][1 << N];

struct node
{
    int x, y;
} e[N];

bool check(int m)
{
    int cnt = 0;
    for (m; m > 0; m -= (m & -m))
        cnt++;
    return cnt >= 4;
}

bool is(int r, int s, int t)
{
    if (e[r].x < min(e[s].x, e[t].x) || e[r].x > max(e[s].x, e[t].x) || e[r].y < min(e[s].y, e[t].y) || e[r].y > max(e[s].y, e[t].y))
        return 0;
    return ((e[s].x - e[r].x) * (e[t].y - e[r].y) - (e[s].y - e[r].y) * (e[t].x - e[r].x) == 0);
}

signed main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        e[i].x = read(), e[i].y = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (is(k, i, j))
                    a[i][j] |= (1 << k - 1);
            }
        }
    queue<pii> q; // {终点，点集}
    for (int i = 1; i <= n; i++)
    {
        vis[i][1 << i - 1] = 1;
        f[i][1 << i - 1] = 1;
        q.push({i, 1 << i - 1});
    }
    int ans = 0;
    bool flag = 0;
    while (q.size())
    {
        int s = q.front().first, m = q.front().second;
        q.pop();
        if (flag || check(m))
        {
            flag = 1;
            ans = (ans + f[s][m]) % mod;
        }
        for (int i = 1, j = 1; i <= n; i++, j <<= 1)
        {
            if (!(j & m))
            {
                // cout << s << " " << m << endl;
                if ((a[s][i] & m) != a[s][i])
                    continue;
                if (!vis[i][j | m])
                {
                    vis[i][j | m] = 1;
                    q.push({i, j | m});
                }
                f[i][j | m] = (f[i][j | m] + f[s][m]) % mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}