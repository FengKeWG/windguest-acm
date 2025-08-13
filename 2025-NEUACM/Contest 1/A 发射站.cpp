#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int h[N], v[N];
int a[N], b[N];

signed main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        h[i] = read(), v[i] = read();
    a[0] = inf;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (s.size() && h[s.top()] <= h[i])
        {
            a[i] += v[s.top()];
            s.pop();
        }
        s.push(i);
    }
    while (s.size())
        s.pop();
    s.push(0);
    for (int i = n; i >= 1; i--)
    {
        while (s.size() && h[s.top()] <= h[i])
        {
            a[i] += v[s.top()];
            s.pop();
        }
        s.push(i);
    }
    int ans = -inf;
    for (int i = 1; i <= n; i++)
        ans = max(ans, a[i]);
    cout << ans;
    return 0;
}