#include <bits/stdc++.h>
#define int __int128
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
x ≡ r1 (mod m1)
x ≡ r2 (mod m2)
x ≡ r3 (mod m3)
m1 m2 m3 互质
求x的最小非负整数解

计算所有m的乘积M，ci = M / mi
计算ci mod mi 的逆元ci^-1
x = ricici^-1 (mod M) 求和
*/

int n;
int m[N], r[N];

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}

int crt()
{
    int M = 1, ans = 0;
    for (int i = 1; i <= n; i++)
        M *= m[i];
    for (int i = 1; i <= n; i++)
    {
        int c = M / m[i], x, y;
        exgcd(c, m[i], x, y);
        ans = (ans + r[i] * c * x % M) % M;
    }
    return (ans % M + M) % M;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        m[i] = read(), r[i] = read();
    print(crt());
    return 0;
}