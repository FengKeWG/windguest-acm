#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

int a[N];
int cnt[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int l = 1, r = 1;
    int ans = inf;
    int k = 1;
    cnt[a[1]] = 1;
    int ll, rr;
    while (l <= r && r <= n)
    {
        if (k == m)
        {
            if (ans > r - l + 1)
            {
                ans = r - l + 1;
                ll = l;
                rr = r;
            }
            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
                k--;
            l++;
        }
        else
        {
            r++;
            cnt[a[r]]++;
            if (cnt[a[r]] == 1)
                k++;
        }
    }
    cout << ll << ' ' << rr << endl;
    return 0;
}