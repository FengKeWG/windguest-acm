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
x ≡ r1 (mod m1)
x ≡ r2 (mod m2)
转换为
x=m1p+r1=m2q+r2
m1p-m2q=r2-r1
裴蜀定理可得，只有r2-r1整除gcd(m1,m2)才有解

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
    x = y1, y1 = x1 - a / b * y1;
    return d;
}

int excrt()
{
    int m1, m2, r1, r2, p, q;
    m1 = m[1], r1 = r[1];
    for (int i = 2; i <= n; i++)
    {
        m2 = m[i], r2 = r[i];
        int d = exgcd(m1, m2, p, q);
        if ((r2 - r1) % d)
            return -1;
        p = (r2 - r1) / d;
        p = (p % (m2 / d) + m2 / d) % (m2 / d);
        r1 = m1 * p + r1;
        m1 = m2 * m2 / d;
    }
    return (r1 % m1 + m1) % m1;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}