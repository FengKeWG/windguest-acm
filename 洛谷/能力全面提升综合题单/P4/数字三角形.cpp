#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

int a[1005][1005];
int f[1005][1005];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int r = read();
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] = read();
    f[1][1] = a[1][1];
    for (int i = 2; i <= r; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
    int ans = 0;
    for (int i = 1; i <= r; i++)
        ans = max(ans, f[r][i]);
    cout << ans << endl;
    return 0;
}