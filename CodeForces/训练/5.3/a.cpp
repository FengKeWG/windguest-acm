#include <bits/stdc++.h>
#define int long long
// #define int __int128
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int x, n;
int ans = 1;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    x = read(), n = read();
    int m = n, y = x;
    ans += n;
    if (x == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    while (m--)
    {
        int z = (int)sqrt(y);
        ans++;
        if (z * z != y && m != 0 && z != 1)
        {
            ans += m;
        }
        y = z;
        if (y == 1)
            break;
    }
    cout << ans << endl;
    return 0;
}