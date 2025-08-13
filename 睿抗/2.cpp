#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define inf LLONG_MAX
#define N 1000005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int c1 = 0, c2 = 0;
        int n, s;
        cin >> n >> s;
        int cnt = 0, tot = 0;
        int r, c;
        for (int i = 1; i <= n; i++)
        {
            cin >> r >> c;
            if (r == 1)
                cnt++;
            tot += c;
        }
        if (tot - s >= 50)
            c2 = 1;
        if (cnt * 2 >= n)
            c1 = 1;
        cout << c1 << ' ' << c2 << endl;
    }
    return 0;
}