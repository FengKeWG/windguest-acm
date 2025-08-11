#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

struct node
{
    int l, r;
    int Max, Min, Max2, Min2;
};

vector<node> t;
vector<int> a;
int _, n, q;

void up(int r)
{
    t[r].Max = max(t[lson].Max, t[rson].Max);
    t[r].Min = min(t[lson].Min, t[rson].Min);
    t[r].Max2 = max({min(t[lson].Max, t[rson].Max), t[lson].Max2, t[rson].Max2});
    t[r].Min2 = min({max(t[lson].Min, t[rson].Min), t[lson].Min2, t[rson].Min2});
}

void build(int r, int x, int y)
{
    t[r] = {x, y, a[x], a[x], -INF, INF};
    if (x == y)
        return;
    build(lson, x, mid);
    build(rson, mid + 1, y);
    up(r);
}

int qmax(int r, int x, int y)
{
    if (y < t[r].l || x > t[r].r)
        return -INF;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].Max;
    return max(qmax(lson, x, y), qmax(rson, x, y));
}

int qmin(int r, int x, int y)
{
    if (y < t[r].l || x > t[r].r)
        return INF;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].Min;
    return min(qmin(lson, x, y), qmin(rson, x, y));
}

int qmax2(int r, int x, int y)
{
    if (y < t[r].l || x > t[r].r)
        return -INF;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].Max2;
    return max({min(qmax(lson, x, y), qmax(rson, x, y)), qmax2(lson, x, y), qmax2(rson, x, y)});
}

int qmin2(int r, int x, int y)
{
    if (y < t[r].l || x > t[r].r)
        return INF;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].Min2;
    return min({max(qmin(lson, x, y), qmin(rson, x, y)), qmin2(lson, x, y), qmin2(rson, x, y)});
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> _;
    while (_--)
    {
        cin >> n;
        a.resize(n + 1);
        t.resize(4 * n + 4);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        // cout << qmax(1, 1, n) << " " << qmax2(1, 1, n) << " " << qmin(1, 1, n) << " " << qmin2(1, 1, n) << endl;
        cin >> q;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            // cout << qmax(1, x, y) << " " << qmax2(1, x, y) << " " << qmin(1, x, y) << " " << qmin2(1, x, y) << endl;
            cout << max(qmax(1, x, y) * qmax2(1, x, y), qmin(1, x, y) * qmin2(1, x, y)) << endl;
        }
    }

    return 0;
}