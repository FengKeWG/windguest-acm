#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
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

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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
问题
给定一个整数n和m个不同的质数p1,p2，…рm
求1～n中能被p1,P2，…,pm中的至少一个数整除的数
有多少个？其中m≤16,n,pi≤10^9

1~n中，能被p整除的数有n/p，能被p1 p2整除的有n/(p1*p2)

使用的二进制位来表示每个集合选与不选的状态。
若有3个质数，就需要3个二进制位来表示所有状态
*/

int n, m, p[N];

int calc()
{
    int res = 0;
    for (int i = 1; i < 1 << m; i++)
    {
        int t = 1, sign = -1; // 容斥原理正负号
        for (int j = 0; j < m; j++)
        {
            if (i & 1 << j)
            {
                if (t * p[j] > n)
                    t = 0, break;
                t *= p[j];
                sign = -sign;
            }
            if (t)
                res += n / t * sign;
        }
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}