#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define MOD 1000000007
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = read();
    while (t--)
    {
        int n = read();
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            b[i] = a[i] ^ b[i - 1];
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            mp[b[i - 1]] *= 3;
            mp[b[i - 1]] += 2 * mp[b[i]];
            mp[b[i - 1]] %= MOD;
            ans += mp[b[i - 1]];
        }
        ans += mp[b[n]];
        cout << ans << endl;
    }
    return 0;
}