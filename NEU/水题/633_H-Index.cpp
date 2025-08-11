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
        for (auto &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        for (int i = n - 1; i >= 1; i--)
        {
            bool br = 0;
            for (int j = n - 1; j >= n - i; j--)
            {
                if (a[j] < i)
                {
                    br = 1;
                    break;
                }
            }
            if (br)
                continue;
            for (int j = 0; j < n - i; j++)
            {
                if (a[j] > i)
                {
                    br = 1;
                    break;
                }
            }
            if (br)
                continue;
            else
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}