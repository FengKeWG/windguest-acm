#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, k, x, a, b, ans;
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
int main()
{
    t = read();
    while (t--)
    {
        n = read();
        k = read();
        m = n - k;
        a = read();
        b = read();
        x = abs(a - b);
        ans = 0;
        if (x == 0)
        {
            printf("%lld\n", ans);
            continue;
        }
        if (a + b == k)
        {
            puts("1");
            continue;
        }
        if (n == k)
        {
            puts("-1");
            continue;
        }
        ans += x / k;
        x = x % k;
        if (x == 0)
        {
            printf("%lld\n", ans);
            continue;
        }
        if (x % 2)
        {
            if (k % 2)
            {
                ans++;
                x = k - x;
            }
            else
            {
                puts("-1");
                continue;
            }
        }
        ans += 2 * (x / (2 * m));
        x = x % (2 * m);
        if (x)
            ans += 2;
        printf("%lld\n", ans);
    }
    return 0;
}