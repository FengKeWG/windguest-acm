#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 1005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

struct node
{
    int x, y, v;
    bool operator<(const node &t) const
    {
        return x < t.x;
    }
} a[N];

int n;
int x0, sum;
int s[N];
int f[N][N][2]; // 收集完l到r之间的所有东西损耗的最小值（反向思考）

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), x0 = read();
    for (int i = 1; i <= n; i++)
        a[i].x = read();
    for (int i = 1; i <= n; i++)
        a[i].y = read();
    for (int i = 1; i <= n; i++)
        a[i].v = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i].v;
        sum += a[i].y;
    }
    memset(f, inf, sizeof f);
    for (int i = 1; i <= n; i++)
        if (a[i].x == x0)
        {
            f[i][i][0] = f[i][i][1] = 0;
            break;
        }
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            f[l][r][0] = min(f[l][r][0], f[l + 1][r][0] + (a[l + 1].x - a[l].x) * (s[n] - s[r] + s[l] - s[0]));
            f[l][r][0] = min(f[l][r][0], f[l + 1][r][1] + (a[r].x - a[l].x) * (s[n] - s[r] + s[l] - s[0]));
            f[l][r][1] = min(f[l][r][1], f[l][r - 1][0] + (a[r].x - a[l].x) * (s[n] - s[r - 1] + s[l - 1] - s[0]));
            f[l][r][1] = min(f[l][r][1], f[l][r - 1][1] + (a[r].x - a[r - 1].x) * (s[n] - s[r - 1] + s[l - 1] - s[0]));
        }
    cout << fixed << setprecision(3) << (sum - min(f[1][n][0], f[1][n][1])) / 1000.0;
    return 0;
}