#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, r;
int a[N], s[N];
int ans = -inf;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), r = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (i >= 1)
        {
            while (q.size() && s[q.back()] >= s[i - 1])
                q.pop_back();
            q.push_back(i - 1);
        }
        while (q.size() && q.front() < i - r)
            q.pop_front();
        if (q.size())
            ans = max(ans, s[i] - s[q.front()]);
    }
    cout << ans << endl;
    return 0;
}