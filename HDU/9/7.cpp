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

int a[N], b[N];
int f[N];
int ans;
int T;
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        ans = 0;
        n = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            b[a[i]] = i;
        }
        f[1] = 1;
        int ans = 1;
        for (int i = 2; i <= n; i++)
        {
            if (b[i - 1] < b[i])
                f[i] = f[i - 1] + 1;
            else
                f[i] = 1;
            if (f[i] > ans)
                ans = f[i];
        }
        cout << n - ans << endl;
    }
    return 0;
}