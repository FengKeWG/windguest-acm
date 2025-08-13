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

void print(int x, int y)
{
    cout << x << " to " << y << endl;
}

void solve(int l, int r)
{
    if (r - l + 1 <= 2)
        return;
    if (r - l + 1 == 10)
    {
        print(r - 2, l - 2);
        print(l + 2, r - 2);
        print(r - 4, l + 2);
        print(l - 1, r - 4);
        print(r - 1, l - 1);
        return;
    }
    if (r - l + 1 == 12)
    {
        print(r - 2, l - 2);
        print(r - 5, r - 2);
        print(l + 1, r - 5);
        print(r - 6, l + 1);
        print(l - 1, r - 6);
        print(r - 1, l - 1);
        return;
    }
    if (r - l + 1 == 14)
    {
        print(l + 7, l - 2);
        print(l + 4, l + 7);
        print(l + 11, l + 4);
        print(l + 2, l + 11);
        print(l + 8, l + 2);
        print(l - 1, l + 8);
        print(l + 12, l - 1);
        return;
    }
    print(r - 2, l - 2);
    print(l + 2, r - 2);
    solve(l + 4, r - 4);
    print(l - 1, r - 5);
    print(r - 1, l - 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    if (n == 3)
    {
        print(2, -1);
        print(5, 2);
        print(3, -3);
    }
    else
        solve(1, 2 * n);
    return 0;
}