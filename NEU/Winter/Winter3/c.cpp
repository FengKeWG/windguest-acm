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

struct node
{
    int d, v;
};

bool cmp(const node &a, const node &b)
{
    if (a.d != b.d)
        return a.d < b.d;
    else
        return a.v > b.v;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int ans = 0;
    int n = read();
    vector<node> a(n);
    for (auto &x : a)
    {
        x.d = read(), x.v = read();
    }
    sort(a.begin(), a.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &x : a)
    {
        if (x.d <= q.size())
        {
            if (x.v > q.top())
            {
                ans -= q.top();
                q.pop();
                ans += x.v;
                q.push(x.v);
            }
        }
        else
        {
            ans += x.v;
            q.push(x.v);
        }
    }
    cout << ans;
    return 0;
}