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
#define int128 __int128
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
int128 a[85][85];
int128 f[85][85];
int128 ans;

void print(int128 x)
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            f[j][j] = a[i][j] << 1;
        for (int len = 2; len <= m; len++)
            for (int l = 1; l + len - 1 <= m; l++)
            {
                int r = l + len - 1;
                f[l][r] = max((f[l + 1][r] << 1) + (a[i][l] << 1), (f[l][r - 1] << 1) + (a[i][r] << 1));
            }
        ans += f[1][m];
    }
    print(ans);
    return 0;
}