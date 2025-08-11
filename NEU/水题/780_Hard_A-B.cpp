#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    string a, b;
    while (getline(cin, a))
    {
        getline(cin, b);
        unordered_map<char, int> mp;
        for (auto &x : b)
            mp[x]++;
        for (auto &x : a)
            if (!mp[x])
                cout << x;
        cout << endl;
    }

    return 0;
}