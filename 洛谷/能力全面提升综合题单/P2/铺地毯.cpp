#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
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

int n;
int a[N], b[N], g[N], k[N];
int x, y;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = read(), g[i] = read(), k[i] = read();
    x = read(), y = read();
    for (int i = 1; i <= n; i++)
        if (a[i] <= x && a[i] + g[i] >= x && b[i] <= y && b[i] + k[i] >= y)
            ans = i;
    cout << (ans == 0 ? -1 : ans) << endl;
    return 0;
}