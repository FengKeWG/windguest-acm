#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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

int n, m;
int s, tt, d;
int a[N];
int ans;

struct node
{
    int l, r, min, add;
} t[N * 4];

void up(int r)
{
    t[r].min = min(t[ls].min, t[rs].min);
}

void cal(node &t, int add)
{
    t.min += add;
    t.add += add;
}

void down(int r)
{
    cal(t[ls], t[r].add);
    cal(t[rs], t[r].add);
    t[r].add = 0;
}

void build(int r, int x, int y)
{
    t[r] = {x, y, a[x], 0};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y, int k)
{
    if (x > t[r].r || y < t[r].l)
        return;
    if (x <= t[r].l && y >= t[r].r)
    {
        cal(t[r], k);
        return;
    }
    down(r);
    change(ls, x, y, k);
    change(rs, x, y, k);
    up(r);
}

int qmin(int r, int x, int y)
{
    if (x > t[r].r || y < t[r].l)
        return inf;
    if (x <= t[r].l && y >= t[r].r)
        return t[r].min;
    down(r);
    return min(qmin(ls, x, y), qmin(rs, x, y));
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    // cout << qmin(1, 1, 1) << endl;
    for (int i = 1; i <= m; i++)
    {
        d = read(), s = read(), tt = read();
        if (qmin(1, s, tt) >= d)
            change(1, s, tt, -d);
        else
        {
            ans = i;
            break;
        }
    }
    if (ans)
    {
        cout << -1 << endl;
        cout << ans << endl;
    }
    else
        cout << 0;
    return 0;
}