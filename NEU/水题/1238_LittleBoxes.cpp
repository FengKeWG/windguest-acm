#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define int128 __uint128_t
using namespace std;

inline int128 read()
{
    int128 x = 0, f = 1;
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

inline void print(int128 n)
{
    if (n > 9)
        print(n / 10);
    putchar(n % 10 + '0');
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = read();
    while (t--)
    {
        int128 a = read(), b = read(), c = read(), d = read();
        int128 ans = a + b + c + d;
        print(ans);
        putchar('\n');
    }
    return 0;
}