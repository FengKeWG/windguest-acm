#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int T;
int n, k;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        int mx = -inf, mn = inf;
        int cnt = 0;
        int s = 0;
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            s += a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        for (int i = 1; i <= n; i++)
            if (a[i] == mx)
                cnt++;
        if (mx - mn > k + 1)
        {
            cout << "Jerry\n";
            continue;
        }
        if (mx - mn > k && cnt > 1)
        {
            cout << "Jerry\n";
            continue;
        }
        if (s & 1)
        {
            cout << "Tom\n";
            continue;
        }
        else
        {
            cout << "Jerry\n";
            continue;
        }
    }
    return 0;
}