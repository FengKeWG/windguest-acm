#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

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

int a[N];

int f(int x, int y)
{
    return x % y + y % x;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        int ans = 0, mx = a[1];
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, f(mx, a[i]));
            if (a[i] > mx)
            {
                if (a[i] >= mx * 2)
                {
                    mx = a[i];
                    for (int j = 1; j <= i; j++)
                        ans = max(ans, f(a[i], a[j]));
                }
                else
                {
                    mx = a[i];
                    ans = mx;
                }
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}
