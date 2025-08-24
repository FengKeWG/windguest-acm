#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 305
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

struct node
{
    int x, y;
} a[N];

int n;
int ans;

double isLeft(node p1, node p2, node p)
{
    node V1, V2;
    V1.x = p1.x - p2.x;
    V1.y = p1.y - p2.y;
    V2.x = p.x - p1.x;
    V2.y = p.y - p1.y;
    double f = V1.x * V2.y - V2.x * V1.y;
    return f;
}

bool isChui(node p1, node p2, node p3)
{
    int x1 = p2.x - p1.x;
    int y1 = p2.y - p1.y;
    int x2 = p3.x - p1.x;
    int y2 = p3.y - p1.y;
    return x1 * x2 + y1 * y2 == 0;
}

long long cal(node a, node b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].x = read();
        a[i].y = read();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            vector<node> C, A, B;
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (isLeft(a[i], a[j], a[k]) == 0)
                    continue;
                if (isLeft(a[i], a[j], a[k]) < 0 && cal(a[i], a[k]) == cal(a[j], a[k]))
                    C.push_back(a[k]);
                else if (isLeft(a[i], a[j], a[k]) > 0)
                {
                    if (isChui(a[i], a[j], a[k]))
                        A.push_back(a[k]);
                    else if (isChui(a[j], a[i], a[k]))
                        B.push_back(a[k]);
                }
            }
            int t = C.size();
            for (auto &p : A)
                for (auto &q : B)
                    if (cal(p, a[i]) == cal(q, a[j]))
                        ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}