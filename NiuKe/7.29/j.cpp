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

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> a, dis;

bool check(int mid)
{
    int l1 = -inf, r1 = inf, l2 = -inf, r2 = inf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dis[i][j] > mid)
            {
                l1 = max(l1, i + j - 2 - mid);
                r1 = min(r1, i + j - 2 + mid);
                l2 = max(l2, i - j - mid);
                r2 = min(r2, i - j + mid);
            }
    if (l1 > r1 || l2 > r2)
        return 0;
    if (max((l1 + l2 + 1) / 2, 0ll) <= min((r1 + r2) / 2, n - 1) && max((l1 - r2 + 1) / 2, 0ll) <= min((r1 - l2) / 2, m - 1))
        return 1;
    else
        return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    a.resize(n + 1, vector<int>(m + 1));
    dis.resize(n + 1, vector<int>(m + 1, inf));
    queue<pii> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read();
            if (a[i][j])
            {
                q.push({i, j});
                dis[i][j] = 0;
            }
        }
    if (q.empty())
    {
        cout << m / 2 + n / 2 << endl;
        return 0;
    }
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dis[nx][ny] == inf)
            {
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int r = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            // cout << dis[i][j] << endl;
            r = max(r, dis[i][j]);
        }
    int l = 0, ans = r;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}