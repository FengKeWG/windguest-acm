#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 400005ll
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

int n, k;
int ans;

struct node
{
    int l, r, max;
} t[N << 2];

void up(int r)
{
    t[r].max = max(t[ls].max, t[rs].max);
}

// void cal(node &t, int mul, int add)
// {
//     t.max = t.max * mul + add;
//     t.mul = t.mul * mul;
//     t.add = t.add * mul + add;
// }

// void down(int r)
// {
//     cal(t[ls], t[r].mul, t[r].add);
//     cal(t[rs], t[r].mul, t[r].add);
//     t[r].add = 0;
//     t[r].mul = 1;
// }

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y;
    if (x == y)
    {
        t[r].max = 0;
        return;
    }
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
        t[r].max = max(t[r].max, k);
        return;
    }
    // down(r);
    change(ls, x, y, k);
    change(rs, x, y, k);
    up(r);
}

int qmax(int r, int x, int y)
{
    if (x > t[r].r || y < t[r].l)
        return -inf;
    if (x <= t[r].l && y >= t[r].r)
        return t[r].max;
    // down(r);
    return max(qmax(ls, x, y), qmax(rs, x, y));
}

signed main()
{
    n = read(), k = read();
    build(1, 1, N);
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        x++;
        change(1, x, x, qmax(1, max(1ll, x - k), min(N, x + k)) + 1);
    }
    cout << t[1].max << endl;
    return 0;
}