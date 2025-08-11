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

struct mat
{
    int c[4][4];
    mat() { memset(c, 0, sizeof c); }
};

mat operator*(mat &x, mat &y)
{
    mat t;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
    return t;
}

void qpow(mat &res, int n)
{
    mat a;
    res.c[1][1] = res.c[1][2] = res.c[1][3] = 1;
    a.c[1][1] = a.c[1][3] = a.c[2][1] = a.c[3][2] = 1;
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        if (n <= 3)
            cout << 1 << endl;
        else
        {
            mat res;
            qpow(res, n - 3);
            cout << res.c[1][1] << endl;
        }
    }
    return 0;
}