#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define MOD 1000000007
#define int128 __uint128_t
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
        int s1 = 0, s2 = 0, s3 = 0;
        int ans = 0;
        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
            s1 += (x % MOD);
            s2 += (x * x) % MOD;
            s3 += (x * x * x) % MOD;
        }
        s1 %= MOD;
        s2 %= MOD;
        s3 %= MOD;
        if (4 - n > 0)
            cout << ((3 * s1 * s2) % MOD - (((4 - n) % MOD) * s3) % MOD) % MOD << endl;
        else
            cout << ((3 * s1 * s2) % MOD + (((n - 4) % MOD) * s3) % MOD) % MOD << endl;
    }

    return 0;
}
