#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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

int s, n, m;
int ans;
int a[105][105]; // 第i个城堡第j个人由多少兵
int f[20005];    // 前i个城堡共出兵j个

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    s = read(), n = read(), m = read();
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= n; j++)
            a[j][i] = read();
    for (int i = 1; i <= n; i++)
        sort(a[i] + 1, a[i] + 1 + s);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            for (int k = 1; k <= s; k++)
                if (j - a[i][k] * 2 > 0)
                {
                    f[j] = max(f[j], f[j - a[i][k] * 2 - 1] + k * i);
                    // cout << i << " " << j << " " << k << " " << f[i][j] << endl;
                    ans = max(ans, f[j]);
                }
    cout << ans;
    return 0;
}