#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

template <typename T>
struct Bit
{
    vector<T> a;
    int n;

    Bit(int n) : n(n), a(n + 1, 0) {}

    T lb(int x)
    {
        return x & -x;
    }

    void change(int x, int k)
    {
        while (x <= n)
        {
            s[x] += k;
            x += lb(x);
        }
    }

    T query(int x)
    {
        T t = 0;
        while (x)
        {
            t += s[x];
            x -= lb(x);
        }
        return t;
    }
};

int n, q;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    Bit<int> b(n);
    while (q--)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            int y = read(), k = read();
            change(x, k);
            change(y + 1, -k);
        }
        else
            cout << a[x] + query(x) << endl;
    }
    return 0;
}