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

struct node
{
    string s;
    int c1, c2;
    bool operator<(const node &t) const
    {
        return c1 * t.c2 > t.c1 * c2;
    }
} a[N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s;
        for (auto &c : a[i].s)
            if (c == 's')
                a[i].c1++;
        a[i].c2 = a[i].s.size() - a[i].c1;
    }
    sort(a + 1, a + 1 + n);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i].s << endl;
    int ans = 0, pre = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto &c : a[i].s)
        {
            if (c == 's')
                pre++;
            else
                ans += pre;
        }
    }
    cout << ans << endl;
    return 0;
}