#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 105
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

// 二维数组尽量让第二维的下标放在循环内层，可以常数优化时间复杂度

struct mat
{
    int c[N][N];
    mat() { memset(c, 0, sizeof c); }
} A, res;
int n, k;

mat operator*(mat &x, mat &y)
{
    mat t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
    return t;
}

void qpow(int k)
{
    for (int i = 1; i <= n; i++)
        res.c[i][i] = 1; // 对角线为1，其余为0是单位矩阵
    while (k)
    {
        if (k & 1)
            res = res * A;
        A = A * A;
        k >>= 1;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}