#include <iostream>
#include <cmath>
#include <cstdio>
#include <climits>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
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

int ans = inf;
int n, m;
int minv[25], mins[25];

void dfs(int d, int v, int s, int R, int H)
{
    if (d == 0)
    {
        if (v == 0)
            ans = min(ans, s);
        return;
    }
    if (s + mins[d] >= ans)
        return;
    if (v < minv[d])
        return;
    if (R < d || H < d)
        return;
    int maxv = 0;
    for (int i = 0; i < d; i++)
    {
        int r = R - i, h = H - i;
        if (r <= 0 || h <= 0)
        {
            maxv = -1;
            break;
        }
        maxv += r * r * h;
        if (maxv >= v)
            break;
    }
    if (maxv < v)
        return;
    int mxr = min((int)floor(sqrt((double)(v - minv[d - 1]))), R);
    for (int r = mxr; r >= d; r--)
    {
        int b = (d == m ? r * r : 0);
        if (s + b + mins[d - 1] >= ans)
            continue;
        int mxh = min((int)((v - minv[d - 1]) / (r * r)), H);
        for (int h = mxh; h >= d; h--)
        {
            int ns = s + b + 2 * r * h;
            if (ns + mins[d - 1] >= ans)
                continue;
            int vol = r * r * h;
            if (vol > v)
                continue;
            dfs(d - 1, v - vol, ns, r - 1, h - 1);
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    minv[0] = 0;
    mins[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }
    if (minv[m] > n)
    {
        cout << 0 << endl;
        return 0;
    }
    dfs(m, n, 0, (int)floor(sqrt((double)n)), n);
    if (ans == inf)
        cout << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}