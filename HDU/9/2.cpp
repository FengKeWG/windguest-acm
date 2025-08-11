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

int T, n;
int a[N], d[N];
int d1[N], d2[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        int m = n - 1;
        for (int i = 0; i < m; i++)
            d[i] = a[i + 2] - a[i + 1];
        {
            int l = 0, r = -1;
            for (int i = 0; i < m; i++)
            {
                int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
                while (i - k >= 0 && i + k < m && d[i - k] == d[i + k])
                    k++;
                d1[i] = k;
                if (i + k - 1 > r)
                {
                    l = i - k + 1;
                    r = i + k - 1;
                }
            }
        }
        {
            int l = 0, r = -1;
            for (int i = 0; i < m; i++)
            {
                int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
                while (i - k - 1 >= 0 && i + k < m && d[i - k - 1] == d[i + k])
                    k++;
                d2[i] = k;
                if (i + k - 1 > r)
                {
                    l = i - k;
                    r = i + k - 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++)
            res += d1[i] + d2[i];
        cout << (n + res) << endl;
    }
    return 0;
}