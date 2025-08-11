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

class DataType
{
private:
    char c;
    int n;
    double m;

public:
    DataType() : c(' '), n(0), m(0.0) {};
    DataType(int c, int n, int m) : c(c), n(n), m(m) {};
    DataType(DataType &t) : c(t.c), n(t.n), m(t.m) {};
    ~DataType() {};

    void out()
    {
        cout << c << " " << n << " ";
        cout << fixed << setprecision(3) << m << endl;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    DataType d1;
    DataType d2('a', 1, 1.0);
    DataType d3 = d2;
    d3.out();
    return 0;
}