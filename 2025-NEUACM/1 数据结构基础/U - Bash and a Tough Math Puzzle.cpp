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

int n, m;
int a[N];
int cnt;

struct node
{
    int l, r, gcd;
} t[N << 2];

void up(int r)
{
    t[r].gcd = __gcd(t[ls].gcd, t[rs].gcd);
}

// void cal(node &t, int add)
// {
//     t.sum += (t.r - t.l + 1) * add;
//     t.min += add;
//     t.add += add;
// }

// void down(int r)
// {
//     if (t[r].add)
//     {
//         cal(t[ls], t[r].add);
//         cal(t[rs], t[r].add);
//         t[r].add = 0;
//     }
// }

void build(int r, int x, int y)
{
    t[r].l = x, t[r].r = y;
    if (x == y)
    {
        t[r].gcd = a[x];
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int x, int k)
{
    if (x > t[r].r || x < t[r].l)
        return;
    if (t[r].l == t[r].r)
    {
        t[r].gcd = k;
        return;
    }
    // down(r);
    change(ls, x, k);
    change(rs, x, k);
    up(r);
}

void query(int r, int x, int y, int k)
{
    if (x > t[r].r || y < t[r].l)
        return;
    if (t[r].gcd % k == 0)
        return;
    if (cnt > 1)
        return;
    if (t[r].l == t[r].r)
    {
        cnt++;
        return;
    }
    query(ls, x, y, k);
    if (cnt > 1)
        return;
    query(rs, x, y, k);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    int q = read();
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int l = read(), r = read(), k = read();
            cnt = 0;
            query(1, l, r, k);
            if (cnt <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int i = read(), k = read();
            change(1, i, k);
        }
    }
    return 0;
}