#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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

struct node
{
    int x, y, z;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n = read(), m = read();
    vector<node> a(n);
    for (auto &x : a)
    {
        x.x = read(), x.y = read(), x.z = read();
    }

    int ans = 0;

    for (int i = -1; i <= 1; i += 2)
    {
        for (int j = -1; j <= 1; j += 2)
        {
            for (int k = -1; k <= 1; k += 2)
            {
                priority_queue<int> q;
                int res = 0;
                for (auto &x : a)
                    q.push(x.x * i + x.y * j + x.z * k);
                for (int p = 1; p <= m; p++)
                {
                    res += q.top();
                    q.pop();
                }
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;

    return 0;
}