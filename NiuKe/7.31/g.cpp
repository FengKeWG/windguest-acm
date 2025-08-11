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

int n, q;
int a[N];
int ans;

struct node
{
    int l, r, c0, c1, f;
} t[N << 2];

void up(int r)
{
    t[r].c0 = t[ls].c0 + t[rs].c0;
    t[r].c1 = t[ls].c1 + t[rs].c1;
    if (t[ls].c1 == 0)
        t[r].f = t[rs].f;
    else if (t[rs].f > 0)
        t[r].f = max(t[ls].f + t[rs].c0, t[rs].f + t[ls].c1);
    else
        t[r].f = t[ls].f + t[rs].c0;
    if (t[rs].c0 > 0 && t[ls].c1 > 0)
        t[r].f = max(t[r].f, t[ls].c1 + t[rs].c0 - 1);
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
    t[r].l = x, t[r].r = y, t[r].f = 0;
    if (x == y)
    {
        t[r].c0 = (a[x] == 0);
        t[r].c1 = (a[x] == 1);
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

void change(int r, int pos)
{
    if (pos > t[r].r || pos < t[r].l)
        return;
    if (t[r].l >= pos && t[r].r <= pos)
    {
        t[r].c0 = (a[pos] == 0);
        t[r].c1 = (a[pos] == 1);
        return;
    }
    change(ls, pos);
    change(rs, pos);
    up(r);
}

signed main()
{
    n = read(), q = read();
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] == 'L' ? 0 : 1;
    build(1, 1, n);
    while (q--)
    {
        int x = read();
        a[x] = a[x] ? 0 : 1;
        change(1, x);
        cout << t[1].f << endl;
    }
    return 0;
}