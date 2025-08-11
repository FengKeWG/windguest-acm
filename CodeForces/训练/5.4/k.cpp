#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 5005
#define M 500005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((x + y) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n;
int ans[N];
vector<int> s[M];
int op1[N], op2[N];
bitset<M> b;
struct node
{
    int l, r;
    vector<int> a;
} t[4 * N];

void build(int r, int x, int y)
{
    t[r] = {x, y};
    if (x == y)
        return;
    build(ls, x, mid);
    build(rs, mid + 1, y);
}

void insert(int r, int x, int y, int v)
{
    if (t[r].l >= x && t[r].r <= y)
    {
        t[r].a.push_back(v);
        return;
    }
    if (t[r].l > y || t[r].r < x)
        return;
    if (y <= mid)
        insert(ls, x, y, v);
    else if (x > mid)
        insert(rs, x, y, v);
    else
        insert(ls, x, mid, v), insert(rs, mid + 1, y, v);
}

void calc(int r)
{
    bitset<M> tmp = b;
    for (auto &v : t[r].a)
        b |= b << v;
    if (t[r].l == t[r].r)
    {
        ans[t[r].l] = b.count() - 1;
        b = tmp;
        return;
    }
    calc(ls);
    calc(rs);
    b = tmp;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
        op1[i] = read(), op2[i] = read();
    for (int i = 1; i <= n; i++)
    {
        if (op1[i] == 1)
            s[op2[i]].push_back(i);
        else
        {
            insert(1, s[op2[i]].back(), i - 1, op2[i]);
            s[op2[i]].pop_back();
        }
    }
    for (int i = 1; i < M; i++)
        for (auto &j : s[i])
            insert(1, j, n, i);
    b[0] = 1;
    calc(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}