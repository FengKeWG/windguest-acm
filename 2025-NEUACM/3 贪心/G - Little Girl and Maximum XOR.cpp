#include <bits/stdc++.h>
#define int unsigned long long
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

// int tot;
// int a[N], b[N];
// int c[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int l = read(), r = read();
    if (l == r)
    {
        cout << 0 << endl;
        return 0;
    }
    // while (l)
    // {
    //     a[++tot] = l & 1;
    //     l >>= 1;
    // }
    // tot = 0;
    // while (r)
    // {
    //     b[++tot] = r & 1;
    //     r >>= 1;
    // }
    // for (int i = 1; i <= tot; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= tot; i++)
    //     cout << b[i] << ' ';
    // cout << endl;
    // bool can = 0;
    // for (int i = tot; i >= 1; i--)
    // {
    //     if (a[i] ^ b[i] == 1)
    //     {
    //         c[i] = 1;
    //         can = 1;
    //     }
    //     else if (can)
    //         c[i] = 1;
    //     // }
    //     // else
    //     //     c[i] = 1;
    // }
    int x = l ^ r;
    int pos = 0;
    while (x >>= 1)
        pos++;
    // int ans = 0;
    // for (int i = 1; i <= tot; i++)
    //     ans += c[i] * (1 << i - 1);
    // cout << ans << endl;
    cout << (1ull << pos + 1) - 1;
    return 0;
}