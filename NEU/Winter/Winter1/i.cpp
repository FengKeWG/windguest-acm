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
    int T = read();
    while (T--)
    {
        int n = read();
        bool can = 1;
        for (int i = 1; i <= n; i++)
        {
            int m = read();
            int move = max((i - 1) * 2, (n - i) * 2);
            if (move >= m)
            {
                can = 0;
            }
        }
        if (can)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}