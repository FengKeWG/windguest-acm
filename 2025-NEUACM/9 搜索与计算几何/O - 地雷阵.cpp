#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
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

int n;
int x, y, R;
double d, t, b;
double l, r;
double res = 0;

struct node
{
    double l, r;
} a[N];

bool cmp(node &a, node &b)
{
    if (a.l != b.l)
        return a.l < b.l;
    else
        return a.r < b.r;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        x = read(), y = read(), R = read();
        d = sqrt(x * x + y * y);
        t = asin(1.0 * min(R, x) / d);
        b = atan(1.0 * y / x);
        l = max(0.0, b - t), r = min(M_PI / 2, b + t);
        a[i] = {l, r};
    }
    sort(a + 1, a + 1 + n, cmp);
    l = a[1].l, r = a[1].r;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].l > r)
        {
            res += r - l;
            l = a[i].l;
            r = a[i].r;
        }
        else if (a[i].r > r)
        {
            r = a[i].r;
        }
    }
    res += r - l;
    printf("%.3lf", 1 - (2 * res / M_PI));
    return 0;
}