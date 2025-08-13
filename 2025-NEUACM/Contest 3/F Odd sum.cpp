#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    int mxj = inf;
    int mxfj = -inf;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        if (a[i] > 0 && a[i] & 1)
            mxj = min(mxj, a[i]);
        if (a[i] < 0 && abs(a[i]) & 1)
            mxfj = max(mxfj, a[i]);
        if (a[i] > 0)
            ans += a[i];
    }
    if (ans == 0)
        cout << mxfj << endl;
    else if (ans & 1)
        cout << ans << endl;
    else
    {
        // cout << ans << " " << mxj << " " << mxfj << endl;
        if (mxj != -inf && mxfj != -inf)
        {
            cout << max(ans - mxj, ans + mxfj);
        }
        else if (mxj != -inf)
            cout << ans - mxj;
        else
            cout << ans + mxfj;
    }
    return 0;
}