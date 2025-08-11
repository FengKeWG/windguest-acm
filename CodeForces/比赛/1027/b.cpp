#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

int t, n, k;
string s;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        int c1 = 0, c0 = 0;
        for (auto &c : s)
        {
            if (c == '0')
                c0++;
            else
                c1++;
        }
        if (c1 / 2 + c0 / 2 == k)
            cout << "YES\n";
        else if (c1 / 2 + c0 / 2 > k)
        {
            int m = c1 / 2, n = c0 / 2;
            int d = m + n - k;
            if (d & 1)
                cout << "NO\n";
            else if (min(m, n) * 2 >= d)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}