#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

int a[N];
unordered_map<int, int> mp;

struct node
{
    int l, r, gcd;
} t[N << 2];

void up(int r)
{
    t[r].gcd = __gcd(t[ls].gcd, t[rs].gcd);
    // mp[t[r].gcd]++;
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
        // mp[t[r].gcd]++;
        return;
    }
    build(ls, x, mid);
    build(rs, mid + 1, y);
    up(r);
}

// void change(int r, int x, int y, int k)
// {
//     if (x > t[r].r || y < t[r].l)
//         return;
//     if (x <= t[r].l && y >= t[r].r)
//     {
//         cal(t[r], k);
//         return;
//     }
//     down(r);
//     change(ls, x, y, k);
//     change(rs, x, y, k);
//     up(r);
// }

int qgcd(int r, int x, int y)
{
    if (x > t[r].r || y < t[r].l)
        return 0;
    if (x <= t[r].l && y >= t[r].r)
        return t[r].gcd;
    int s = qgcd(ls, x, y), t = qgcd(rs, x, y);
    if (s == 0)
        return t;
    else if (t == 0)
        return s;
    else
        return __gcd(s, t);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    // build(1, 1, n);
    unordered_map<int, int> now, nxt;
    for (int i = 1; i <= n; i++)
    {
        nxt.clear();
        for (auto &p : now)
        {
            nxt[__gcd(p.first, a[i])] += p.second;
        }
        nxt[a[i]]++;
        swap(now, nxt);
        for (auto &p : now)
            mp[p.first] += p.second;
    }
    int q = read();
    while (q--)
    {
        int x = read();
        cout << mp[x] << endl;
    }
    return 0;
}