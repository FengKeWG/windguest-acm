#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int _;
    cin >> _;
    while (_--)
    {
        double n;
        cin >> n;
        double ans = 0;
        for (int i = 1; i <= n; i++)
            ans += 1.0 / i;
        cout << fixed << setprecision(4) << ans << endl;
    }

    return 0;
}