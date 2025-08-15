#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    int ans = n * k;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        if (k / l != 0)
            r = min(k / (k / l), n);
        else
            r = n;
        ans -= (k / l) * (r - l + 1) * (l + r) / 2;
    }
    cout << ans << endl;
    return 0;
}