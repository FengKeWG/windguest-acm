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
        string a;
        cin >> a;
        reverse(a.begin(), a.end());
        for (auto &x : a)
        {
            if (x == 'p')
                x = 'q';
            else if (x == 'q')
                x = 'p';
        }
        cout << a << endl;
    }

    return 0;
}