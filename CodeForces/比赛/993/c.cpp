#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int ans = 0;
        int A = min(m, a);
        int B = min(m, b);
        int C = min(2 * m - A - B, c);
        cout << A + B + C << endl;
    }

    return 0;
}