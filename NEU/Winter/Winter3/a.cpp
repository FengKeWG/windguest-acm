#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
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
    int n = read();
    vector<int> a(n);
    unordered_map<int, int> mp;
    for (auto &x : a)
    {
        x = read();
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                mp[i]++;
                if (i != x / i)
                {
                    mp[x / i]++;
                }
            }
        }
    }
    int ans = 0;
    for (auto &x : a)
    {
        ans += mp[x] - 1;
    }
    cout << ans << endl;
    return 0;
}
