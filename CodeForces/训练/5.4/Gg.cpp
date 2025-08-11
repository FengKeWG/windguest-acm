#include <bits/stdc++.h>
// #define int __int128
#define endl '\n'
#define N 1000005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

struct node
{
    int l, r, max;
} t[4 * N];
vector<int> c[N];
int a[N];
int n, k;
long long ans;
int T;

inline void build(int r, int x, int y)
{
    t[r] = {x, y, a[x]};
    if (x == y)
        return;
    int mid = (t[r].l + t[r].r) >> 1;
    build(ls, x, mid);
    build(rs, mid + 1, y);
    t[r].max = max(t[ls].max, t[rs].max);
}

inline int qmax(int r, int x, int y)
{
    if (t[r].l > y || t[r].r < x)
        return -inf;
    if (t[r].l >= x && t[r].r <= y)
        return t[r].max;
    return max(qmax(ls, x, y), qmax(rs, x, y));
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        ans = 0;
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            c[a[i]].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            c[a[i]].push_back(i);
        }
        build(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j + k - 1 < c[i].size(); j++)
            {
                int x = c[i][j], y = c[i][j + k - 1];
                int L = x, R = y;
                if (qmax(1, x, y) > i)
                    continue;
                int l, r;
                if (j == 0)
                    l = 1;
                else
                    l = c[i][j - 1] + 1;
                r = x;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (qmax(1, mid, x) == i)
                    {
                        r = mid - 1;
                        L = mid;
                    }
                    else
                        l = mid + 1;
                }
                l = y, r = n;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if (qmax(1, y, mid) == i)
                    {
                        l = mid + 1;
                        R = mid;
                    }
                    else
                        r = mid - 1;
                }
                ans += (x - L + 1) * (R - y + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}