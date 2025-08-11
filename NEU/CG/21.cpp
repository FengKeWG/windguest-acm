#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y);
    void show();
    Point operator++(int);
    Point operator++();
    Point operator--(int);
    Point operator--();
};

Point::Point(int x, int y) : x(x), y(y) {};
void Point::show()
{
    cout << "(" << x << "," << y << ")" << endl;
}
Point Point::operator++(int)
{
    Point tmp = *this;
    x++;
    y++;
    return tmp;
}
Point Point::operator++()
{
    x++;
    y++;
    return *this;
}
Point Point::operator--(int)
{
    Point tmp = *this;
    x--;
    y--;
    return tmp;
}
Point Point::operator--()
{
    x--;
    y--;
    return *this;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int x = read(), y = read();
    Point p(x, y);
    p.show();
    (p++).show();
    (++p).show();
    (p--).show();
    (--p).show();
    return 0;
}