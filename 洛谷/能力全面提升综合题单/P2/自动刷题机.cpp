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

int n, k;
int a[N];
int cal(int x)
{
    int now = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        now += a[i];
        if (now < 0)
            now = 0;
        if (now >= x)
        {
            cnt++;
            now = 0;
        }
    }
    return cnt;
}

int mn, mx;

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int l = 0, r = 1e18;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (int res = cal(mid); res <= k)
        {
            r = mid;
            if (res == k)
                mn = mid;
        }
        else
            l = mid;
    }
    l = 0, r = 1e18;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (int res = cal(mid); res >= k)
        {
            l = mid;
            if (res == k)
                mx = mid;
        }
        else
            r = mid;
    }
    if (mn && mx)
        cout << mn << " " << mx;
    else
        cout << -1;
    return 0;
}