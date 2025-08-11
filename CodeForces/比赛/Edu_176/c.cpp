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

int n, m;
int a[N];
int s[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= m; i++)
        {
            a[i] = read();
            if (a[i] > n - 1)
                a[i] = n - 1;
        }
        sort(a + 1, a + 1 + m);
        for (int i = 1; i <= m; i++)
            s[i] = s[i - 1] + a[i];
        int ans = 0;
        for (int i = 1; i < m; i++)
        {
            int l = n - a[i];
            int idx = lower_bound(a + i + 1, a + m + 1, l) - a;
            // cout << idx << endl;
            if (idx <= m)
                ans += (s[m] - s[idx - 1] - (m - idx + 1) * l + (m - idx + 1));
        }
        cout << ans * 2 << endl;
    }

    return 0;
}