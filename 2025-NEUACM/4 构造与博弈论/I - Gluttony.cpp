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

int a[N], b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int idx = upper_bound(b + 1, b + 1 + n, a[i]) - b;
        if (idx > n)
            a[i] = b[1];
        else
            a[i] = b[idx];
        cout << a[i] << ' ';
    }
    return 0;
}