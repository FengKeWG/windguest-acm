#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf (LLONG_MAX >> 1)
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

unordered_map<int, int> mp;

void de(int x)
{
    mp.clear();
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0)
        {
            mp[i]++;
            x /= i;
        }
    if (x > 1)
        mp[x]++;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    for (int t = 1; t <= T; t++)
    {
        cout << "Case " << t << ": ";
        int n = read();
        int m = n < 0 ? -n : n;
        de(m);
        int ans = 0;
        for (auto &[x, y] : mp)
            ans = gcd(ans, y);
        if (n < 0)
            while (ans % 2 == 0)
                ans /= 2;
        cout << ans << endl;
    }
    return 0;
}