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

int n;
int a[N];
int s[N];
int l1[N], l2[N];
int r1[N], r2[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }
    stack<int> s1, s2;
    for (int i = 1; i <= n; i++)
    {
        l1[i] = i;
        l2[i] = i;
        while (s1.size() && a[s1.top()] >= a[i])
        {
            l1[i] = l1[s1.top()];
            s1.pop();
        }
        s1.push(i);
        while (s2.size() && a[s2.top()] <= a[i])
        {
            l2[i] = l2[s2.top()];
            s2.pop();
        }
        s2.push(i);
    }
    while (s1.size())
        s1.pop();
    while (s2.size())
        s2.pop();
    for (int i = n; i >= 1; i--)
    {
        r1[i] = i;
        r2[i] = i;
        while (s1.size() && a[s1.top()] > a[i])
        {
            r1[i] = r1[s1.top()];
            s1.pop();
        }
        s1.push(i);
        while (s2.size() && a[s2.top()] < a[i])
        {
            r2[i] = r2[s2.top()];
            s2.pop();
        }
        s2.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << l1[i] << ' ' << l2[i] << ' ' << r1[i] << ' ' << r2[i] << endl;
        ans += (i - l2[i] + 1) * (r2[i] - i + 1) * a[i];
        ans -= (i - l1[i] + 1) * (r1[i] - i + 1) * a[i];
    }
    cout << ans;
    return 0;
}