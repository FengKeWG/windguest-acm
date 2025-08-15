#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2005
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    double ans = 0;
    int n = read();
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n < 100000)
        for (int i = 1; i < n; i++)
            ans += 1.0 / i;
    else
        ans = log(n) + 0.577215664901532;
    cout << fixed << setprecision(5) << ans + 1 << endl;
    return 0;
}
