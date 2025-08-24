#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-12
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

int x[N], y[N], xp, yp, a[N];

int cal(int a, int b)
{
    return (x[a] - xp) * (y[b] - yp) - (y[a] - yp) * (x[b] - xp);
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), y[i] = read();
    xp = read(), yp = read();
    int s = 0;
    for (int i = 1; i < n; i++)
        s += a[i] = cal(i, i + 1);
    s += a[n] = cal(n, 1);
    int tot = 0;
    for (int i = n + 1; i <= 2 * n; i++)
        a[i] = a[i - n];
    int ans = inf;
    for (int l = 1, r = 1; l <= 2 * n; tot -= a[l++])
    {
        while (2 * tot < s && r <= 2 * n)
            tot += a[r++];
        ans = min(ans, min(abs(2 * tot - s), abs(2 * (tot - a[r - 1]) - s)));
    }
    cout << ans << endl;
}
