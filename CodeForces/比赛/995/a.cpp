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
    int t = read();
    while (t--)
    {
        int n = read();
        vector<int> a(n), b(n);
        for (auto &x : a)
            x = read();
        for (auto &x : b)
            x = read();
        b.push_back(0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i + 1] > 0)
            {
                ans += a[i] - b[i + 1];
            }
        }
        cout << ans << endl;
    }

    return 0;
}