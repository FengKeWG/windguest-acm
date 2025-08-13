#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (s[r].l + s[r].r >> 1)
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
string s, S;
int a[N], b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    string t1 = s.substr(0, n), t2 = s.substr(n, n);
    string T2 = t2;
    reverse(T2.begin(), T2.end());
    string T1 = t1;
    reverse(T1.begin(), T1.end());
    string s1 = t1 + '#' + T2, s2 = T1 + '#' + t2;
    int l = 0, r = 0;
    for (int i = 1; i < s1.size(); i++)
    {
        if (i <= r)
            a[i] = min(r - i + 1, a[i - l]);
        while (i + a[i] < s1.size() && s1[a[i]] == s1[i + a[i]])
            a[i]++;
        if (i + a[i] - 1 > r)
        {
            l = i;
            r = i + a[i] - 1;
        }
    }
    l = 0, r = 0;
    for (int i = 1; i < s2.size(); i++)
    {
        if (i <= r)
            b[i] = min(r - i + 1, b[i - l]);
        while (i + b[i] < s2.size() && s2[b[i]] == s2[i + b[i]])
            b[i]++;
        if (i + b[i] - 1 > r)
        {
            l = i;
            r = i + b[i] - 1;
        }
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
    {
        bool can1 = 1, can2 = 1;
        if (i > 0 && a[t1.size() + 1 + n - i] < i)
            can1 = 0;
        if (i < n && b[t2.size() + 1 + i] < (n - i))
            can2 = 0;
        if (can1 && can2)
        {
            ans = i;
            break;
        }
    }
    if (!~ans)
    {
        cout << -1 << endl;
        return 0;
    }
    string p;
    if (ans > 0)
    {
        p = t2.substr(0, ans);
        reverse(p.begin(), p.end());
        S += p;
    }
    if (ans < n)
    {
        p = t1.substr(ans);
        reverse(p.begin(), p.end());
        S += p;
    }
    cout << S << endl
         << ans << endl;
    return 0;
}