#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-12
#define inf (LLONG_MAX >> 1)
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

struct node
{
    int x, d, c;
    bool operator<(const node &t) const
    {
        return d < t.d;
    }
};

int a[N];
unordered_map<int, int> mp;
vector<int> res;
vector<node> b;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + 1 + n);
    b.push_back({1, inf, -1});
    b.push_back({n, inf, 1});
    for (int i = 1; i < n; i++)
    {
        int d = a[i + 1] - a[i] - 1;
        if (d == 0)
            continue;
        // cout << d << endl;
        if (d & 1)
        {
            // cout << (d >> 1) << ' ' << (d >> 1 | 1) << endl;
            if (d >> 1)
                b.push_back({i, d >> 1, 1});
            b.push_back({i + 1, (d >> 1) + 1, -1});
        }
        else
        {
            b.push_back({i, d >> 1, 1});
            b.push_back({i + 1, d >> 1, -1});
        }
    }
    sort(b.begin(), b.end());
    // for (auto &[x, d, c] : b)
    //     cout << x << ' ' << d << ' ' << c << endl;
    int ans = 0;
    int D = 1;
    int idx = 0;
    while (1)
    {
        for (int i = idx; i < b.size(); i++)
        {
            auto [x, d, c] = b[i];
            // cout << x << ' ' << d << ' ' << c << endl;
            ans += D;
            res.push_back(a[x] + D * c);
            if (--m == 0)
                break;
            if (d == D)
                idx++;
        }
        if (!m)
            break;
        D++;
    }
    cout << ans << endl;
    for (auto &x : res)
        cout << x << ' ';
    return 0;
}