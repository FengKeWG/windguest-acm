#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 3005
#define M 100005
#define mod 998244353
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

char s[N], p[N];
int f[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s%s", s + 1, p + 1);
    int n = strlen(s + 1), m = strlen(p + 1);
    for (int i = m + 1; i <= n; i++)
        p[i] = ' ';
    for (int i = 0; i <= n; i++)
        f[i + 1][i] = 1;
    for (int len = 1; len <= n; len++)
    {
        char c = s[len];
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if (p[l] == ' ' || c == p[l])
                f[l][r] = (f[l][r] + f[l + 1][r]) % mod;
            if (p[r] == ' ' || c == p[r])
                f[l][r] = (f[l][r] + f[l][r - 1]) % mod;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << f[i][j] << " ";
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = m; i <= n; i++)
        ans = (ans + f[1][i]) % mod;
    cout << ans << endl;
    return 0;
}