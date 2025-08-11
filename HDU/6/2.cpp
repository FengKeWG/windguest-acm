#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define M 18
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, x;
int a[N], d[N];
int lg[N];
int st[N][M];

int query(int l, int r)
{
    int j = lg[r - l + 1];
    return max(st[l][j], st[r - (1 << j) + 1][j]);
}

bool check(int k)
{
    int res = d[n];
    for (int l = 1; l <= n - k + 1; l++)
    {
        int r = l + k - 1;
        int mx = query(l, r);
        int w = 0;
        if (l > 1)
        {
            w += d[l - 1];
        }
        if (l > 1)
        {
            w += abs(mx - a[l - 1]);
        }
        if (r < n)
        {
            w += abs(a[r + 1] - mx);
        }
        if (r < n - 1)
        {
            w += (res - d[r + 1]);
        }
        if (w <= x)
        {
            return 1;
        }
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    lg[1] = 0;
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
    int T = read();
    while (T--)
    {
        n = read(), x = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
            st[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        for (int i = 2; i <= n; i++)
            d[i] = d[i - 1] + abs(a[i] - a[i - 1]);
        if (d[n] <= x)
        {
            cout << 0 << endl;
            continue;
        }
        int l = 1, r = n;
        int ans = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}