#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 3000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

int n;
int f[N];
vector<int> a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read(), y = read();
        mx = max(mx, y);
        a[y].push_back(x);
    }
    for (int r = 1; r <= mx; r++)
    {
        f[r] = f[r - 1];
        for (auto &l : a[r])
        {
            f[r] = max(f[r], f[l - 1] + r - l + 1);
        }
    }
    cout << f[mx] << endl;
    return 0;
}