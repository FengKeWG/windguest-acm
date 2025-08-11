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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b;
        for (auto &x : a)
            cin >> x;
        for (int i = 0; i < n - 1; i++)
        {
            b.push_back(a[i + 1] - a[i] - 1);
        }
        int ans = 0;
        if (b[0] < b[b.size() - 1])
        {
            for (int i = 1; i < b.size(); i++)
            {
                ans += b[i];
            }
        }
        else
        {
            for (int i = 0; i < b.size() - 1; i++)
            {
                ans += b[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}