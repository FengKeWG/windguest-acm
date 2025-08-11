#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define inf LLONG_MAX
// #define mid ((t[r].l + t[r].r) >> 1)
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

struct node
{
    int l, r, sum;
    int add, min;
} t1[N << 2], t2[N << 2];

void up1(int r)
{
    t1[r].sum = (t1[ls].sum + t1[rs].sum);
    t1[r].min = min(t1[ls].min, t1[rs].min);
}

void up2(int r)
{
    t2[r].sum = (t2[ls].sum + t2[rs].sum);
    t2[r].min = min(t2[ls].min, t2[rs].min);
}

void calc(node &t, int add)
{
    t.sum += (t.r - t.l + 1) * add;
    t.min += add;
    t.add += add;
}

void down1(int r)
{
    if (t1[r].add != 0)
    {
        calc(t1[ls], t1[r].add);
        calc(t1[rs], t1[r].add);
        t1[r].add = 0;
    }
}

void down2(int r)
{
    if (t2[r].add != 0)
    {
        calc(t2[ls], t2[r].add);
        calc(t2[rs], t2[r].add);
        t2[r].add = 0;
    }
}

void build1(int r, int x, int y)
{
    t1[r] = {x, y, 0, 0, 0};
    if (x == y)
        return;
    int mid = ((t1[r].l + t1[r].r) >> 1);
    build1(ls, x, mid);
    build1(rs, mid + 1, y);
    up1(r);
}

void build2(int r, int x, int y)
{
    t2[r] = {x, y, 0, 0, 0};
    if (x == y)
        return;
    int mid = ((t2[r].l + t2[r].r) >> 1);
    build2(ls, x, mid);
    build2(rs, mid + 1, y);
    up2(r);
}

void change1(int r, int x, int y, int add)
{
    if (t1[r].l > y || t1[r].r < x)
        return;
    if (t1[r].l >= x && t1[r].r <= y)
    {
        calc(t1[r], add);
        return;
    }
    down1(r);
    change1(ls, x, y, add);
    change1(rs, x, y, add);
    up1(r);
}

void change2(int r, int x, int y, int add)
{
    if (t2[r].l > y || t2[r].r < x)
        return;
    if (t2[r].l >= x && t2[r].r <= y)
    {
        calc(t2[r], add);
        return;
    }
    down2(r);
    change2(ls, x, y, add);
    change2(rs, x, y, add);
    up2(r);
}

int qsum1(int r, int x, int y)
{
    if (t1[r].l > y || t1[r].r < x)
        return 0;
    if (t1[r].l >= x && t1[r].r <= y)
        return t1[r].sum;
    down1(r);
    return (qsum1(ls, x, y) + qsum1(rs, x, y));
}

int qsum2(int r, int x, int y)
{
    if (t2[r].l > y || t2[r].r < x)
        return 0;
    if (t2[r].l >= x && t2[r].r <= y)
        return t2[r].sum;
    down2(r);
    return (qsum2(ls, x, y) + qsum2(rs, x, y));
}

int qmin1(int r, int x, int y)
{
    if (t1[r].l > y || t1[r].r < x)
        return inf;
    if (t1[r].l >= x && t1[r].r <= y)
        return t1[r].min;
    down1(r);
    return min(qmin1(ls, x, y), qmin1(rs, x, y));
}

int qmin2(int r, int x, int y)
{
    if (t2[r].l > y || t2[r].r < x)
        return inf;
    if (t2[r].l >= x && t2[r].r <= y)
        return t2[r].min;
    down2(r);
    return min(qmin2(ls, x, y), qmin2(rs, x, y));
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), q = read();
    build1(1, 1, n);
    build2(1, 1, n);
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int x = read(), y = read();
            change1(1, x, x, 1);
            change2(1, y, y, 1);
        }
        else if (op == 2)
        {
            int x = read(), y = read();
            change1(1, x, x, -1);
            change2(1, y, y, -1);
        }
        else
        {
            int x1 = read(), y1 = read(), x2 = read(), y2 = read();
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            if ((qsum1(1, x1, x2) >= x2 - x1 + 1 && qmin1(1, x1, x2) != 0) || (qsum2(1, y1, y2) >= y2 - y1 + 1 && qmin2(1, y1, y2) != 0))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}