#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
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

struct node
{
    int x, y;
    bool operator<(const node &t) const
    {
        return y < t.y;
    }
} a[N];

int ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i].x = read(), a[i].y = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1, r = -1; i <= n; i++)
    {
        if (a[i].x >= r)
        {
            ans++;
            r = a[i].y;
        }
    }
    cout << ans << endl;
    return 0;
}