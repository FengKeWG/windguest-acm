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

int n;
char s[55];
int f[55][55];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s + 1;
    n = strlen(s + 1);
    memset(f, inf, sizeof f);
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (s[l] == s[r])
                f[l][r] = min(f[l][r - 1], f[l + 1][r]); // 本题特殊的，如果两端相等，一开始就可以刷过去了
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]); // 区间 dp 核心
        }
    cout << f[1][n];
    return 0;
}