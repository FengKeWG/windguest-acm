#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int ans = 0;
    int h = 2;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 3)
        {
            ans += a[i] / 3;
            a[i] %= 3;
        }
        h = max(h, i + 1);
        while (1)
        {
            if (h > n)
                break;
            if (!a[i])
                break;
            if (a[h] >= 2)
            {
                a[h] -= 2;
                a[i]--;
                ans++;
            }
            else
                h++;
        }
    }
    cout << ans << endl;
    return 0;
}