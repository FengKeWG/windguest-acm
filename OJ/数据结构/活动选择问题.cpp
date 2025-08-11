#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
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

struct node
{
    int s, t;
    bool operator<(const node &tt) const
    {
        return t < tt.t;
    }
} a[N];
int n;
int ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].s = read(), a[i].t = read();
    sort(a + 1, a + 1 + n);
    a[0].t = -1;
    int last = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].s > last)
        {
            ans++;
            last = a[i].t;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i][0] << " " << f[i][1] << endl;
    cout << ans;
    return 0;
}