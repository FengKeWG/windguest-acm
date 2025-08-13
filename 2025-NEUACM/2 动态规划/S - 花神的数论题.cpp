#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 75
#define M 100005
#define mod 10000007
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

int f[N][N];
int a[N];
int b[N];
int cnt;

int qpow(int a, int b)
{
    int res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    f[1][1] = 1;
    for (int i = 0; i < N; i++)
        f[i][0] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
    int n = read();
    while (n)
    {
        a[++cnt] = n & 1ll;
        n >>= 1ll;
    }
    // cout << c1 << endl;
    // for (int i = 1; i <= c1; i++)
    //     b[i]++;
    int c1 = 0;
    for (int i = cnt; i > 0; i--)
    {
        if (a[i])
        {
            for (int j = 0; j < i; j++)
            {
                b[j + c1] = b[j + c1] + f[i - 1][j];
                // cout << j + c1 << " " << b[j + c1] << endl;
            }
            c1++;
        }
    }
    b[c1]++;
    // for (int i = 1; i <= cnt; i++)
    //     cout << i << ": " << b[i] << endl;
    int ans = 1;
    for (int i = 1; i <= cnt; i++)
        ans = ans * qpow(i, b[i]) % mod;
    cout << ans << endl;
    return 0;
}