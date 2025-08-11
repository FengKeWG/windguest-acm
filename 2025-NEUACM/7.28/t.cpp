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

int h[N], a[N];
int c[N];
int n, m, k, p;

bool check(int mid)
{
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] + m * a[i] <= mid)
            continue;
        q.push({-mid / a[i], i}), c[i] = 0;
    }
    int cnt = 0;
    for (int i = 1; q.size() && i <= m; i++)
        for (int j = 1; q.size() && j <= k; j++)
        {
            if (-q.top().first < i)
                return 0;
            int x = q.top().second;
            q.pop();
            int w = (mid + (++c[x]) * p) / a[x];
            if (w < m)
                q.push({-w, x});
            cnt++;
        }
    for (int i = 1; i <= n; i++)
    {
        int w = mid + c[i] * p - m * a[i];
        if (h[i] <= w)
            continue;
        w = (h[i] - w - 1) / p + 1;
        if (cnt + w > m * k)
            return 0;
        cnt += w;
    }
    return 1;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), k = read(), p = read();
    int l = 0, r = inf;
    for (int i = 1; i <= n; i++)
    {
        h[i] = read(), a[i] = read();
        l = max(l, a[i]), r = max(r, h[i] + m * a[i]);
    }
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}