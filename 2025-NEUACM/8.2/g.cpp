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

int cal(int n)
{
    if (n == 0)
        return 0;
    if (n % 4 == 0)
        return n - 1;
    if (n % 4 == 1)
        return n;
    if (n % 4 == 2)
        return n;
    if (n % 4 == 3)
        return n + 1;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            res ^= cal(a[i]);
        }
        if (res)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}