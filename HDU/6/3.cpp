#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
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

int a[N], c[N];
int d[N], s[N];
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int ans = -inf;
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            ans = max(ans, a[i]);
            s[i] = s[i - 1] + a[i];
        }
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            c[i] = a[i] + x;
            d[i] = c[i] - c[i - 1];
            if (d[i] == 0)
            {
                if (!l)
                    l = i;
                else
                    r = i;
            }
            else
            {
                if (l && !r)
                    ans = max(ans, (s[l] - s[l - 2]) * 2);
                if (l && r)
                    ans = max(ans, (s[r] - s[l - 2]) * (r - l + 2));
                l = 0, r = 0;
            }
        }
        if (l && !r)
            ans = max(ans, (s[l] - s[l - 2]) * 2);
        if (l && r)
            ans = max(ans, (s[r] - s[l - 2]) * (r - l + 2));
        cout << ans << endl;
    }
    return 0;
}