#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
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

inline int de(int n)
{
    int sum = 0;
    while (n)
    {
        n /= 5;
        sum += n;
    }
    return sum;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    for (int t = 1; t <= T; t++)
    {
        cout << "Case " << t << ": ";
        int q = read();
        int l = 0, r = q * 5, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int x = de(mid);
            if (x >= q)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (ans != -1 && de(ans) == q)
            cout << ans << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}