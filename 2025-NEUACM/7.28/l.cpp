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
int ans[N];
int ti[N];
vector<pii> c;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        b[i] = read();
        c.push_back({min(a[i], b[i]), i});
    }
    sort(c.begin(), c.end());
    int t = 1, h = n;
    for (auto &[x, i] : c)
    {
        if (x == a[i])
            ans[t++] = i;
        else
            ans[h--] = i;
    }
    for (int i = 1; i <= n; i++)
        ti[i] = ti[i - 1] + a[ans[i]];
    int sum = ti[1] + b[ans[1]];
    for (int i = 2; i <= n; i++)
        sum = max(ti[i], sum) + b[ans[i]];
    cout << sum << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}