#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, x, y;
vector<ll, vector<ll>> a;
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
    n = read();
    m = read();
    a.resize(n + 10, vector<ll>(m + 10, 0));
    x = 1;
    y = 1;
    a[x][y] = 1;
    for (int i = 1; i < n * m; i++)
    {
        if (i % 2)
        {
            now = i % n;
            if (a[(x + now - 1) % n + 1][y] == 0)
            {
                x = (x + now - 1) % n + 1;
                a[x][y] = i + 1;
                continue;
            }
            if (a[(x - now + n - 1) % n + 1][y] == 0)
            {
                x = (x - now + n - 1) % n + 1;
                a[x][y] = i + 1;
                continue;
            }
        }
        else
        {
            now = i % m;
            if (a[x][(y + now - 1) % m + 1] == 0)
            {
                y = (y + now - 1) % m + 1;
                a[x][y] = i + 1;
                continue;
            }
            if (a[x][(y - now + m - 1) % m + 1] == 0)
            {
                y = (y - now + m - 1) % m + 1;
                a[x][y] = i + 1;
                continue;
            }
        }
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%lld ", a[i][j]);
        puts("")
    }
    return 0;
}