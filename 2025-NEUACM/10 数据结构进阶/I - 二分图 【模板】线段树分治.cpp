#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 400005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
#define mid (x + y >> 1)
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
int n, m, k, p[N], high[N], top;
struct node
{
    int x, y, hy;
} st[N];
vector<pii> tr[N];
bool ans[N];

int find(int x)
{
    while (x != p[x])
        x = p[x];
    return p[x];
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (high[x] > high[y])
        swap(x, y);
    st[++top] = {x, y, high[y]};
    p[x] = y;
    high[y] += (high[x] == high[y]);
}

void insert(int r, int x, int y, int L, int R, pii e)
{
    if (L > y || R < x)
        return;
    if (L <= x && y <= R)
        return tr[r].push_back(e);
    insert(ls, x, mid, L, R, e);
    insert(rs, mid + 1, y, L, R, e);
}

void solve(int r, int x, int y)
{
    int flag = 0;
    int now = top;
    for (auto &e : tr[r])
    {
        merge(e.first, e.second + n);
        merge(e.second, e.first + n);
        if (find(e.first) == find(e.second))
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        if (x == y)
            ans[x] = 1;
        else
            solve(ls, x, mid), solve(rs, mid + 1, y);
    }
    while (top > now)
    {
        node t = st[top--];
        p[t.x] = t.x;
        high[t.y] = t.hy;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= 2 * n; i++)
        p[i] = i;
    for (int i = 1, x, y, l, r; i <= m; i++)
    {
        x = read(), y = read(), l = read(), r = read();
        insert(1, 1, k, l + 1, r, {x, y});
    }
    solve(1, 1, k);
    for (int i = 1; i <= k; i++)
        cout << (ans[i] ? "Yes\n" : "No\n");
    return 0;
}