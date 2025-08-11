#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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

int n, q;
int s1[N], s2[N];

int lb(int x)
{
    return x & -x;
}

void change(int *s, int x, int k)
{
    while (x <= n)
    {
        s[x] += k;
        x += lb(x);
    }
}

int query(int *s, int x)
{
    int t = 0;
    while (x)
    {
        t += s[x];
        x -= lb(x);
    }
    return t;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        int k = read();
        change(s1, i, k);
        change(s1, i + 1, -k);
        change(s2, i, k * (i - 1));
        change(s2, i + 1, -k * i);
    }
    while (q--)
    {
        int op = read(), x = read(), y = read();
        if (op == 1)
        {
            int k = read();
            change(s1, x, k);
            change(s1, y + 1, -k);
            change(s2, x, k * (x - 1));
            change(s2, y + 1, -k * y);
        }
        else
        {
            cout << (query(s1, y) * y - query(s2, y)) - (query(s1, x - 1) * (x - 1) - query(s2, x - 1)) << endl;
        }
    }
    return 0;
}