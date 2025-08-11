#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
#define mid (t[r].l + t[r].r >> 1)
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

struct tree
{
    double x, h, p1, p2;
} a[N];

struct mush
{
    double x, z;
} b[N];
double d[N];

struct node
{
    int l, r;
    double sum;
    double mul;
} t[N << 2];

void up(int r)
{
    t[r].sum = t[ls].sum + t[rs].sum;
}

void cal(node &t, double mul)
{
    t.sum = (t.sum * mul);
    t.mul = t.mul * mul;
}

void down(int r)
{
    cal(t[ls], t[r].mul);
    cal(t[rs], t[r].mul);
    t[r].mul = 1;
}

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y, t[r].mul = 1;
    if (x == y)
    {
        t[r].sum = d[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int y, double k)
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

double qsum(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return 0;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].sum;
    down(r);
    return qsum(ls, x, y) + qsum(rs, x, y);
}

vector<int> v;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].x = read(), a[i].h = read(), a[i].p1 = read(), a[i].p2 = read();
        a[i].p1 /= 100;
        a[i].p2 /= 100;
        v.push_back(a[i].x);
        v.push_back(a[i].x - a[i].h);
        v.push_back(a[i].x + a[i].h);
    }
    for (int i = 1; i <= m; i++)
    {
        b[i].x = read(), b[i].z = read();
        v.push_back(b[i].x);
    }
    sort(v.begin(), v.end());
    int len = unique(v.begin(), v.end()) - v.begin();
    // cout << len << endl;
    for (int i = 1; i <= m; i++)
    {
        int x = lower_bound(v.begin(), v.begin() + len, b[i].x) - v.begin() + 1;
        // cout << x << endl;
        d[x] += b[i].z;
    }
    build(1, 1, len);
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        l = lower_bound(v.begin(), v.begin() + len, a[i].x - a[i].h) - v.begin() + 1;
        r = lower_bound(v.begin(), v.begin() + len, a[i].x) - v.begin() + 1;
        // cout << l << " " << r << endl;
        change(1, l, r - 1, 1.0 - a[i].p1);
        l = lower_bound(v.begin(), v.begin() + len, a[i].x) - v.begin() + 1;
        r = lower_bound(v.begin(), v.begin() + len, a[i].x + a[i].h) - v.begin() + 1;
        // cout << l << " " << r << endl;
        change(1, l + 1, r, 1.0 - a[i].p2);
    }
    cout << fixed << setprecision(10) << t[1].sum << endl;
    return 0;
}