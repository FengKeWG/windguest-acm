#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-12
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

int n;
double b, X, Y, lstx, lsty, x, y, s;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> b >> lstx >> lsty;
    X = lstx, Y = lsty;
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y;
        s += (lstx * y - x * lsty);
        lstx = x;
        lsty = y;
    }
    x = X, y = Y;
    s += (lstx * y - x * lsty);
    cout << fixed << setprecision(4) << fabs(0.5 * s * b) << endl;
    return 0;
}
