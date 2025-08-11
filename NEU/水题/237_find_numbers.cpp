#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n)
    {
        set<int> s;
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
            mp[x]++;
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
        }
        vector<int> ans;
        for (auto &x : s)
        {
            if (mp[x] & 1)
                ans.push_back(x);
        }
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}