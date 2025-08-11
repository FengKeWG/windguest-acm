#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int n, m;
int a[N];
int f[N][2];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    memset(f, inf, sizeof f);
    for (int i = 1; i <= m; i++)
        a[i] = read();
    f[1][0] = a[1] + 1;
    f[1][1] = 1;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (f[i][0] > f[i - j][0] + a[i] - a[i - j] + qpow(f[i - j][1] + j, 4) - qpow(f[i - j][1], 4))
            {
                f[i][0] = f[i - j][0] + a[i] - a[i - j] + qpow(f[i - j][1] + j, 4) - qpow(f[i - j][1], 4);
                f[i][1] = f[i - j][1] + j;
            }
        }
        if (f[i][0] >= f[i - 1][0] + a[i] + 1)
        {
            f[i][0] = f[i - 1][0] + a[i] + 1;
            f[i][1] = 1;
            // cout << i << endl;
        }
    }
    // cout << f[15][1] << endl;
    // cout << f[m][1] << endl;
    cout << f[m][0] << endl;
    return 0;
}