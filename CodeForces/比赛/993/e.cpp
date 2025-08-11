#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF intONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        if (k == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int cnt = 0, po = 1;
        while (po <= r2)
        {
            int ce = (l2 + po - 1) / po;
            int fl = r2 / po;
            int minn = max(l1, ce);
            int maxn = min(r1, fl);
            if (minn <= maxn)
                cnt += (maxn - minn + 1);
            if (po * k > r2)
                break;
            po *= k;
        }
        cout << cnt << endl;
    }
    return 0;
}