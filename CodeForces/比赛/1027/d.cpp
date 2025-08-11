#include <bits/stdc++.h>
#define int long long
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

struct node
{
    int x, y;
} a[N];
int xs[N], ys[N];

int cal(int x1, int x2, int y1, int y2)
{
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int t, n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    t = read();
    while (t--)
    {
        n = read();
        for (int i = 0; i < n; i++)
        {
            a[i].x = read(), a[i].y = read();
            xs[i] = a[i].x;
            ys[i] = a[i].y;
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        sort(xs, xs + n);
        sort(ys, ys + n);
        int x1 = xs[0];
        int x2 = xs[n - 1];
        int y1 = ys[0];
        int y2 = ys[n - 1];
        int ans = cal(x1, x2, y1, y2);
        for (int i = 0; i < n; i++)
        {
            node p = a[i];
            int X1, X2, Y1, Y2;
            if (p.x == xs[0] && xs[0] < xs[1])
            {
                X1 = xs[1];
            }
            else
            {
                X1 = xs[0];
            }
            if (p.x == xs[n - 1] && xs[n - 1] > xs[n - 2])
            {
                X2 = xs[n - 2];
            }
            else
            {
                X2 = xs[n - 1];
            }
            if (p.y == ys[0] && ys[0] < ys[1])
            {
                Y1 = ys[1];
            }
            else
            {
                Y1 = ys[0];
            }
            if (p.y == ys[n - 1] && ys[n - 1] > ys[n - 2])
            {
                Y2 = ys[n - 2];
            }
            else
            {
                Y2 = ys[n - 1];
            }
            int w = X2 - X1 + 1;
            int h = Y2 - Y1 + 1;
            int A = w * h;
            int cur;
            if (n - 1 < A)
            {
                cur = A;
            }
            else
            {
                cur = min((w + 1) * h, w * (h + 1));
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}