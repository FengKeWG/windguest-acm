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

int a[N];
unordered_map<int, int> mp;

void de(int x)
{
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
    int T = read();
    while (T--)
    {
        mp.clear();
        int n = read();
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            de(x);
        }
        int ans = 0, cnt = 0;
        for (auto &[x, y] : mp)
        {
            //  cout << x << ' ' << y << endl;
            ans += y / 2;
            cnt += y % 2;
        }
        ans += cnt / 3;
        cout << ans << endl;
    }
    return 0;
}