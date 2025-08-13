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

int f[5][N], g[N];
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        f[1][i] = f[1][i - 1] + (a[i] == 1);
        f[2][i] = max(f[1][i], f[2][i - 1] + (a[i] == 2));
        f[3][i] = max(f[2][i], f[3][i - 1] + (a[i] == 1));
        f[4][i] = max(f[3][i], f[4][i - 1] + (a[i] == 2));
        ans = max(ans, f[4][i]);
    }
    cout << ans << endl;
    return 0;
}