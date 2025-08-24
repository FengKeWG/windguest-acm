#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 100010
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
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

struct Point
{
    double x, y;
} p[N], s[N];

int n, top;

double cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(Point a, Point b)
{
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}

double andrew()
{
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        while (top > 1 && cross(s[top - 1], s[top], p[i]) <= 0)
            top--;
        s[++top] = p[i];
    }
    int t = top;
    for (int i = n - 1; i >= 1; i--)
    {
        while (top > t && cross(s[top - 1], s[top], p[i]) <= 0)
            top--;
        s[++top] = p[i];
    }
    double res = 0;
    for (int i = 1; i < top; i++)
        res += dis(s[i], s[i + 1]);
    return res;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    cout << fixed << setprecision(2) << andrew() << endl;
    return 0;
}