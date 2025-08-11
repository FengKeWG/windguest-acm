#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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
    int n = read();
    int a = 0;
    while (n--)
    {
        int y = read(), m = read(), d = read();
        int ans = 0;
        for (int i = 1; i < y; i++)
        {
            if (i % 3 == 0)
                ans += 200;
            else
                ans += 195;
        }
        for (int j = 1; j < m; j++)
        {
            if (y % 3 == 0)
                ans += 20;
            else
            {
                if (j % 2 != 0)
                    ans += 20;
                else
                    ans += 19;
            }
        }
        ans += d - 1;
        cout << 196470 - ans << endl;
    }
    return 0;
}