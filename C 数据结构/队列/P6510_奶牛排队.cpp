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
    vector<int> a(n);
    for (auto &x : a)
        x = read();
    deque<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (q.size() && a[i] <= q.front())
        {
            q.pop_front();
        }
        while (q.size() && a[i] <= q.back())
        {
            q.pop_back();
        }
        q.push_back(a[i]);
        ans = max(ans, (int)q.size());
    }
    cout << ans;
    return 0;
}