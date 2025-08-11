#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 2005
#define M 1005
#define MOD 100000000
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

int n, F;
int a[N];
int f[N][M];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), F = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < F; j++)
        {
            f[i][j] = f[i - 1][j];
            f[i][j] = (f[i][j] + f[i - 1][((j - a[i] % F) + F) % F]) % MOD;
        }
    }
    cout << (f[n][0] - 1 + MOD) % MOD << endl;
    return 0;
}