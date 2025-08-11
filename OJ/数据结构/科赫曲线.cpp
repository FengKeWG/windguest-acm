#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-9
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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
    double x, y;
};

int n;
vector<node> a;
const double q3 = sqrt(3) / 2;

node calc(node l, node r)
{
    double x1 = l.x, y1 = l.y;
    double x2 = r.x, y2 = r.y;
    double x3 = (x1 + x2) / 2, y3 = (y1 + y2) / 2;
    // double k1 = (y2 - y1) / (x2 - x1);
    double d = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    double dx = x2 - x1, dy = y2 - y1;
    // if (k1 == 0)
    // {
    //     return {x3, y3 + q3 * d};
    // }
    // double k2 = -1 / k1;
    // double sin = k2 / sqrt(k2 * k2 + 1);
    // double cos = 1 / sqrt(k2 * k2 + 1);
    // double dx = q3 * cos, dy = q3 * sin;
    // // if (pos)
    // return {x3 + dx, y3 + dy};
    // else
    //     return {x3 - dx, y3 - dy};
    double nx = x3 - dy * q3;
    double ny = y3 + dx * q3;
    return {nx, ny};
}

void koch(node l, node r, int m)
{
    if (m == n)
        return;
    node p = {(2 * l.x + r.x) / 3, (2 * l.y + r.y) / 3};
    node q = {(2 * r.x + l.x) / 3, (2 * r.y + l.y) / 3};
    node s = calc(p, q);
    koch(l, p, m + 1);
    a.push_back(p);
    koch(p, s, m + 1);
    a.push_back(s);
    koch(s, q, m + 1);
    a.push_back(q);
    koch(q, r, m + 1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    a.push_back({0, 0});
    koch({0, 0}, {100, 0}, 0);
    a.push_back({100, 0});
    for (auto &x : a)
        cout << fixed << setprecision(9) << x.x << " " << x.y << endl;
    return 0;
}