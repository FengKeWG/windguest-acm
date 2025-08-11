#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 105
#define M 25005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int T, n, ans;
int a[N];
bool f[M];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        memset(f, 0, sizeof f);
        f[0] = 1;
        n = read();
        ans = n;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
            if (f[a[i]])
                ans--;
            else
                for (int j = a[i]; j <= a[n]; j++)
                    f[j] |= f[j - a[i]];
        cout << ans << endl;
    }
    return 0;
}