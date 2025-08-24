#include <bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
#define N 2050
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
#define lb(x) x & -x
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
struct node
{
    int s[N][N];
    void change(int x, int y, int v)
    {
        for (int i = x; i <= n; i += lb(i))
            for (int j = y; j <= m; j += lb(j))
                s[i][j] += v;
    }
    int query(int x, int y)
    {
        int t = 0;
        for (int i = x; i; i -= lb(i))
            for (int j = y; j; j -= lb(j))
                t += s[i][j];
        return t;
    }
} A, B, C, D;

void add(int x, int y, int v)
{
    A.change(x, y, v);
    B.change(x, y, v * x);
    C.change(x, y, v * y);
    D.change(x, y, v * x * y);
}

int sum(int x, int y)
{
    return A.query(x, y) * (x * y + x + y + 1) - B.query(x, y) * (y + 1) - C.query(x, y) * (x + 1) + D.query(x, y);
}

signed main()
{
    char op;
    cin >> op;
    n = read(), m = read();
    while (cin >> op)
    {
        int a = read(), b = read(), c = read(), d = read();
        if (op == 'L')
        {
            int v = read();
            add(a, b, v);
            add(a, d + 1, -v);
            add(c + 1, b, -v);
            add(c + 1, d + 1, v);
        }
        else
            cout << sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1) << endl;
    }
}