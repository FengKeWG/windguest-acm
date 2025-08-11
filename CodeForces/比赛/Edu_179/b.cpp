#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int t;
int n, m;
int a[11];
int w, l, h;

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    a[1] = 1, a[2] = 2;
    for (int i = 3; i <= 10; i++)
        a[i] = a[i - 1] + a[i - 2];
    t = read();
    while (t--)
    {
        n = read(), m = read();
        for (int i = 1; i <= m; i++)
        {
            w = read(), l = read(), h = read();
            if (a[n] + a[n - 1] <= max({w, l, h}) && min({w, l, h}) >= a[n])
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}