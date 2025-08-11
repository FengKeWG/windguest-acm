#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, w;
struct node
{
    int v, w;
    long double p;
    bool operator<(const node &t) const
    {
        return p > t.p;
    }
} a[N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    n = read(), w = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].v = read(), a[i].w = read();
        a[i].p = (long double)a[i].v / a[i].w;
    }
    sort(a + 1, a + 1 + n);
    long double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (w == 0)
            break;
        if (a[i].w <= w)
        {
            ans += a[i].v;
            w -= a[i].w;
        }
        else
        {
            ans += a[i].p * w;
            w = 0;
            break;
        }
    }
    printf("%.10Lf\n", ans);
    return 0;
}