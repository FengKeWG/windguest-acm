#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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
    multiset<int> ms;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = read();
        if (i == 1)
        {
            ans += m;
            ms.insert(m);
        }
        else
        {
            ms.insert(m);
            auto it = ms.find(m);
            if (it == ms.begin())
            {
                ans += abs(*next(it) - m);
            }
            else if (it == prev(ms.end()))
            {
                ans += abs(*prev(it) - m);
            }
            else
            {
                ans += min(abs(*next(it) - m), abs(*prev(it) - m));
            }
        }
    }
    cout << ans;
    return 0;
}