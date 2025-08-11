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
        int n;
        cin >> n;
        vector<int> a(n), b(n), c;
        unordered_map<int, int> mp, mp2;
        mp[-1] = 1;
        set<int> now;
        now.insert(-1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp2[a[i]]++;
            if (now.find(a[i]) == now.end())
            {
                b[i] = a[i];
                mp[a[i]]++;
                if (mp[a[i]] == mp[*now.begin()])
                {
                    now.insert(a[i]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!mp2[i])
                c.push_back(i);
        }
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 0)
            {
                b[i] = c[idx];
                idx++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}