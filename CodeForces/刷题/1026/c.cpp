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
    int l, r;
} b[N];
int a[N];
int T, n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        int t = 0, p = 0;
        stack<int> s;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            if (a[i] == 1)
                t++;
            else if (a[i] == -1)
            {
                p++;
                s.push(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            b[i].l = read();
            b[i].r = read();
        }
        int x = -inf, y = inf;
        for (int i = n; i >= 1; i--)
        {
            int l = b[i].l, r = b[i].r;
            if (i != n && a[i] == -1 && max(0ll, r - t) < y)
            {
                a[i + 1] = 1;
                x--, y--;
                p--;
            }
            x = max(x, max(0ll, l - t));
            y = min(y, max(0ll, r - t));
            if (x > p)
            {
                cout << -1 << endl;
                break;
            }
            if (a[i] == 1)
                t--;
        }
    }
    return 0;
}