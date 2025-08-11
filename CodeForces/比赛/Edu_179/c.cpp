#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
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

int t, n;
int x;

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    t = read();
    while (t--)
    {
        n = read();
        int ans = inf;
        int l = -1, r = -1;
        int last = -1;
        for (int i = 1; i <= n; i++)
        {
            x = read();
            if (last == -1)
            {
                last = x;
                l = 1, r = 1;
                continue;
            }
            if (x == last)
            {
                r++;
            }
            else
            {
                ans = min(ans, last * (l - 1 + n - r));
                l = i,
                r = i;
                last = x;
            }
        }
        ans = min(ans, last * (l - 1 + n - r));
        cout << ans << endl;
    }
    return 0;
}