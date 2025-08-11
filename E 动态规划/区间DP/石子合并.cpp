#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 305
#define MOD 1000000007
#define eps 1e-6
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

int n;
int a[MAXN];
int s[MAXN];
int f[MAXN][MAXN];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
        f[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)         // 阶段：枚举区间长度
        for (int l = 1; l + len - 1 <= n; l++) // 状态：枚举区间起点
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++) // 决策：枚举分割点
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    cout << f[1][n];
    return 0;
}