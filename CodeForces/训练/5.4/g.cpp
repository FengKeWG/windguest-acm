#include <bits/stdc++.h>
// #define int long long
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

// struct node
// {
//     int l, r, max;
// } t[4 * N];
vector<int> c[N];
long long f[20][N];
int g[25];
int a[N];
long long p[N];
long long n, k, q, res;
long long ans;
int T;

// inline void build(int r, int x, int y)
// {
//     t[r] = {x, y, a[x]};
//     if (x == y)
//         return;
//     int mid = (t[r].l + t[r].r) >> 1;
//     build(ls, x, mid);
//     build(rs, mid + 1, y);
//     t[r].max = max(t[ls].max, t[rs].max);
// }

// inline int qmax(int r, int x, int y)
// {
//     if (t[r].l > y || t[r].r < x)
//         return -inf;
//     if (t[r].l >= x && t[r].r <= y)
//         return t[r].max;
//     return max(qmax(ls, x, y), qmax(rs, x, y));
// }

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 2; i < N; i++)
    {
        p[i] = p[i >> 1] + 1;
    }
    T = read();
    while (T--)
    {
        ans = 0;
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            c[i].clear();
            f[0][i] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            c[a[i]].push_back(i);
        }
        for (int i = 1; 1 << i <= n; i++)
            for (int j = 1; j + (1 << i) - 1 <= n; j++)
                f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
        //  build(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j + k - 1 < c[i].size(); j++)
            {
                int x = c[i][j], y = c[i][j + k - 1];
                int L = x, R = y;
                q = p[y - x + 1];
                if (max(f[q][x], f[q][y - (1 << q) + 1]) > i)
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
                    q = p[x - mid + 1];
                    res = max(f[q][mid], f[q][x - (1 << q) + 1]);
                    if (res == i)
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
                    q = p[mid - y + 1];
                    res = max(f[q][y], f[q][mid - (1 << q) + 1]);
                    if (res == i)
                    {
                        l = mid + 1;
                        R = mid;
                    }
                    else
                        r = mid - 1;
                }
                ans += 1ll * (x - L + 1) * (R - y + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}