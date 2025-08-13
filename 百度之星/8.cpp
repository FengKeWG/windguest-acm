#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define mod 1000000009
#define endl '\n'
#define pii pair<int, int>
#define inf LLONG_MAX / 2
using namespace std;

int a[N];
unordered_map<int, int> mp;

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        mp.clear();
        int n, x, y;
        cin >> n >> x >> y;
        int mx = -inf;
        int ans = inf;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            mp[a[i]]++;
        }
        int mxn = 0;
        for (int i = 1; i <= n; i++)
        {
            mxn = max(mxn, mp[a[i]]);
        }
        ans = min(mx * x, (n - mxn) * y);
        // cout << mx * x << ' ' << (n - mxn) * y << endl;
        sort(a + 1, a + 1 + n);
        for (int i = n; i >= 1; i--)
        {
            ans = min(ans, (n - i) * y + a[i] * x);
        }
        cout << ans << endl;
    }
    return 0;
}