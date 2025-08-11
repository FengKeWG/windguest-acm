#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int m, n;
    while (cin >> m >> n)
    {
        if (n == 1)
        {
            cout << m << endl;
            continue;
        }
        int p = m % n == 0 ? n : m % n;
        if (m % n == 0)
            m--;
        vector<bool> a(p + 1);
        a[0] = 1;
        int ans = 0;
        ans += ceil((double)m / n);
        a[p] = 1;
        ans += m / n;
        if (!a[p - 1])
        {
            ans++;
            a[p - 1] = 1;
        }
        if (!a[1])
            ans++;
        cout << ans << endl;
    }

    return 0;
}