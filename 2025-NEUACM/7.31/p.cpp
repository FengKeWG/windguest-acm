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
int n, l, r;

int f(int x, int l, int r)
{
    return (x % (l + r)) / l;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), l = read(), r = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int m = 0;
    for (int i = 1; i <= n; i++)
        m ^= f(a[i], l, r);
    if (m == 0)
        cout << "Second\n";
    else
        cout << "First\n";
    return 0;
}