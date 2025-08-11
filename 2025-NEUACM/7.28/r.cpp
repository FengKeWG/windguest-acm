#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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
int K[N];
int ans[N];
int tot;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 0; i < 55; i++)
        K[i] = 2;
    while (k)
    {
        K[tot++] = k & 1;
        k >>= 1;
    }
    bool has = 0;
    for (int j = 50; j >= 0; j--)
    {
        int c1 = 0, c0 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >> j & 1)
                c1++;
            else
                c0++;
        }
        if (c1 >= c0)
        {
            ans[j] = 0;
            if (K[j] == 1)
                has = 1;
        }
        else
        {
            if (K[j] == 2)
                ans[j] = 0;
            else if (K[j] == 0 && !has)
                ans[j] = 0;
            else
                ans[j] = 1;
        }
    }
    int r = 0;
    for (int j = 0; j < 50; j++)
        r += ans[j] * (1ll << j);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] ^ r;
    cout << ans << endl;
    return 0;
}