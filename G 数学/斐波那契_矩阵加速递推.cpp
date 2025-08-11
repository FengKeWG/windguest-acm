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

/*
求斐波那契数列 mod MOD
https://www.bilibili.com/video/BV1id4y137ak?t=70.1
*/

struct mat
{
    int c[3][3];
    mat() { memset(c, 0, sizeof c); }
} F, A; // F是斐波那契矩阵，A是构造矩阵

/*
构造 [Fn-1 Fn-2] x A = [Fn Fn-1]。
发现 [F2 F1] * A ^ (n-2) = [Fn Fn-1]
*/

mat operator*(mat &x, mat &y)
{
    mat t;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            for (int k = 1; k <= 2; k++)
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % MOD;
    return t;
}

void qpow(int n)
{
    F.c[1][1] = F.c[1][2] = 1;             // 初始化斐波那契数列
    A.c[1][1] = A.c[1][2] = A.c[2][1] = 1; // 我们构造的矩阵
    while (n)
    {
        if (n & 1)
            F = F * A;
        A = A * A;
        n >>= 1;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    if (n <= 2)
        cout << 1;
    else
    {
        qpow(n - 2);
        cout << F.c[1][1];
    }
    return 0;
}