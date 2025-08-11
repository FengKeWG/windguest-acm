#include <bits/stdc++.h>
#define int long long
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

int T;
int n, a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        int s = 0;
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            s += a[i];
        }
        int m = s / n;
        int shao = 0;
        int duo = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == m)
                continue;
            else if (a[i] > m)
                duo += a[i] - m;
            else
            {
                ans += m - a[i];
                shao += m - a[i];
            }
        }
        cout << max(shao, duo) << endl;
    }
    return 0;
}