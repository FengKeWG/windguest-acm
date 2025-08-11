#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

vector<int> a;
int b[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read(), d = read(), l = read();
    for (int i = 1; i <= n; i++)
    {
        int s = read();
        if (s < l)
            continue;
        if (d == 0)
            a.push_back(inf);
        else
        {
            int c = (s - l) / d;
            if (c > n)
                c = n;
            a.push_back(c);
        }
    }
    if (d == 0)
    {
        cout << a.size() << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    int cur = 0, ans = 0;
    for (auto &x : a)
    {
        while (cur <= n && b[cur] == m)
            cur++;
        if (cur > n)
            break;
        if (cur <= x)
        {
            b[cur]++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}