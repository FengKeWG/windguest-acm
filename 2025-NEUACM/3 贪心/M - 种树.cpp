#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 300005
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
int l[N], r[N];
bool vis[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        q.push({a[i], i});
    }
    for (int i = 0; i <= n + 1; i++)
    {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    int ans = 0, cnt = 0;
    while (cnt < k && q.size())
    {
        auto [x, i] = q.top();
        // cout << x << endl;
        q.pop();
        if (vis[i])
            continue;
        if (x != a[i])
            continue;
        if (a[i] <= 0)
            break;
        ans += a[i];
        cnt++;
        if (l[i] >= 1)
            vis[l[i]] = 1;
        if (r[i] <= n)
            vis[r[i]] = 1;
        if (l[i] >= 1 && r[i] <= n)
        {
            a[i] = a[l[i]] + a[r[i]] - a[i];
            l[i] = l[l[i]];
            if (l[i] >= 0)
                r[l[i]] = i;
            r[i] = r[r[i]];
            if (r[i] <= n + 1)
                l[r[i]] = i;
            q.push({a[i], i});
        }
        else
        {
            vis[i] = 1;
            if (l[i] >= 0)
                r[l[i]] = r[i];
            if (r[i] <= n + 1)
                l[r[i]] = l[i];
        }
    }
    cout << ans << endl;
    return 0;
}