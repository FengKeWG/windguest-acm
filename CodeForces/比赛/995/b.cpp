#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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

    int t = read();
    while (t--)
    {
        int n = read(), a = read(), b = read(), c = read();
        int k = (double)n / (a + b + c);
        int ans = 3 * k;
        n %= (a + b + c);
        if (n > 0)
        {
            n -= a;
            ans++;
        }
        if (n > 0)
        {
            n -= b;
            ans++;
        }
        if (n > 0)
        {
            n -= c;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}