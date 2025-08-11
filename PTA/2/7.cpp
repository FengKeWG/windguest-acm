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

int x, y, n;
int ans1 = -1, ans2 = -1;
int diff = inf;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    x = read(), y = read(), n = read();
    for (int i = 1; i < n; i++)
    {
        int j = n - i;
        if (j <= 0)
            continue;
        if (x % i == 0 && y % j == 0)
        {
            int s0 = x / i;
            int s1 = y / j;
            if (s0 > 1 && s1 > 1)
            {
                if (abs(s0 - s1) < diff)
                {
                    diff = abs(s0 - s1);
                    ans1 = i;
                    ans2 = j;
                }
            }
        }
    }
    if (~ans1)
        cout << ans1 << " " << ans2 << endl;
    else
        cout << "No Solution" << endl;
    return 0;
}