#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 105
#define int128 __int128_t
using namespace std;

int128 fib[N];

inline void print(int128 n)
{
    if (n > 9)
        print(n / 10);
    putchar(n % 10 + '0');
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    fib[0] = 0, fib[1] = 1;
    if (n <= 1)
    {
        print(fib[n]);
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    print(fib[n]);
    putchar('\n');
    return 0;
}