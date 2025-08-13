#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, sum, ans;
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
    ans = 1e18;
    n = read();
    for (ll i = 1; i <= n; i++)
        sum += i;
    for (ll i = 1; i * i <= sum; i++)
        if (sum % i == 0)
            ans = min(ans, 2 * (sum / i + i));
    printf("%lld", ans);
    return 0;
}