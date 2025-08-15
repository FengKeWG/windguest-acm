#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
// #define mod 1000000007
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int x = read(), y = read(), m = read(), n = read(), l = read();
    int b = n - m, a = x - y;
    if (b < 0)
    {
        b = -b;
        a = -a;
    }
    int x1, y1;
    int ans = exgcd(b, l, x1, y1);
    if (a % ans != 0)
        cout << "Impossible\n";
    else
        cout << ((x1 * (a / ans)) % (l / ans) + (l / ans)) % (l / ans);
    return 0;
}