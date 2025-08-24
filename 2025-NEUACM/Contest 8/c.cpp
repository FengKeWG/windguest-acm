#include <bits/stdc++.h>
#define int unsigned long long
#define int128 __uint128_t
#define endl '\n'
#define N 200005
// #define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf (LLONG_MAX >> 1)
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

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a >= 0 ? a : -a;
    }
    int x1, y1;
    int d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int inv(int a, int m)
{
    int x = 0, y = 0;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int a, b, c, k;
    while (cin >> a >> b >> c >> k)
    {
        if (a == 0 && b == 0 && c == 0 && k == 0)
            break;
        int m = (1ull << k);
        a %= m;
        b %= m;
        c %= m;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        if (c == 0)
        {
            cout << "FOREVER\n";
            continue;
        }
        int g = gcd(c, m);
        int d = (b + m - a) % m;
        if (d % g != 0ull)
        {
            cout << "FOREVER\n";
            continue;
        }
        int cg = c / g;
        int mg = m / g;
        int128 dg = d / g;
        cout << (int)(dg * inv(cg, mg)) % mg << endl;
    }
    return 0;
}