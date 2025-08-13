#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define mod 1000000009
#define endl '\n'
#define pii pair<int, int>
#define inf LLONG_MAX / 2
using namespace std;

signed main()
{
    int n;
    cin >> n;
    // for (n = 2; n <= 10; n++)
    // {
    //     vector<int> a;
    //     for (int i = 1; i <= n; i++)
    //         a.push_back(i);
    //     int ans = -inf;
    //     do
    //     {
    //         int res = __gcd(a[0], a[1] * 2);
    //         for (int i = 2; i < n; i++)
    //             res = __gcd(res, a[i] * (i + 1));
    //         // cout << res << endl;
    //         ans = max(ans, res);
    //     } while (next_permutation(a.begin(), a.end()));
    //     sort(a.begin(), a.end());
    //     do
    //     {
    //         int res = __gcd(a[0], a[1] * 2);
    //         for (int i = 2; i < n; i++)
    //             res = __gcd(res, a[i] * (i + 1));
    //         if (res == ans)
    //             break;
    //     } while (next_permutation(a.begin(), a.end()));
    //     for (auto &x : a)
    //         cout << x << ' ';
    //     cout << endl;
    // }
    vector<int> a;
    if (n & 1)
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
    else
        for (int i = 2; i <= n; i += 2)
            cout << i << ' ' << i - 1 << ' ';
    return 0;
}