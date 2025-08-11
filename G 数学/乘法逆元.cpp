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
#define int128 __int128
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
a * x ≡ 1 (mod m)
即: a * x + m * y = 1

exgcd(30, 12, x, y)
gcd(30, 12) = 6
且 (x, y) 是满足方程 30*x + 12*y = 6 的整数解
*/

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

/*
a与m互质时，对于方程ax≡1(mod m)，
求a的乘法逆元x (0<x<m)

转换为不定方程ax+my=1;
因为am互质，所以ax+my=gcd(a,m);
*/

int a, m, x, y;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    a = read(), m = read();
    exgcd(a, m, x, y);
    cout << (x % m + m) % m;
    return 0;
}