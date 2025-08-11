#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 105
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
    int t, f, h;
    bool operator<(const node &x) const
    {
        return t < x.t;
    }
} a[N];

int d, g;
int f[N][105];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    d = read(), g = read();
    for (int i = 1; i <= g; i++)
        a[i].t = read(), a[i].f = read(), a[i].h = read();
    sort(a + 1, a + 1 + g);
    memset(f, -inf, sizeof f);
    f[0][0] = 10;
    int maxLife = 10; // 记录最大存活时间
    for (int i = 1; i <= g; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (f[i - 1][j] >= a[i].t)
            {
                f[i][j] = max(f[i][j], f[i - 1][j] + a[i].f);
            }
            if (j >= a[i].h && f[i - 1][j - a[i].h] >= a[i].t)
            {
                f[i][j] = max(f[i][j], f[i - 1][j - a[i].h]);
                if (j >= d)
                {
                    cout << a[i].t << endl;
                    return 0;
                }
            }
        }
        for (int j = 0; j <= d; j++)
        {
            maxLife = max(maxLife, f[i][j]);
        }
    }
    cout << maxLife << endl; // 如果出不去，输出最大存活时间
    return 0;
}