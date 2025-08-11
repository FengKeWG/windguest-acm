#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 1000005
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

int a[N];
int f[N][3];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    memset(f, inf, sizeof f);
    f[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            f[i][2] = min({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
            f[i][1] = f[i - 1][0] + 1;
            f[i][0] = f[i - 1][0] + 2;
        }
        else if (a[i] == 0)
        {
            f[i][2] = f[i - 1][2] + 1;
            f[i][1] = min({f[i - 1][0], f[i - 1][1]});
            f[i][0] = f[i - 1][0] + 1;
        }
        else
        {
            f[i][2] = f[i - 1][2] + 2;
            f[i][0] = f[i - 1][0];
        }
        // cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << endl;
    }
    int ans = inf;
    for (int i = 0; i < 3; i++)
        ans = min(ans, f[n][i]);
    if (ans == inf)
        cout << "BRAK" << endl;
    else
        cout << ans << endl;
    return 0;
}