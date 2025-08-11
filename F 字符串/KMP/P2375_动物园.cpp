#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1000005
#define MOD 1000000007
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int len = s.size();
        vector<int> N(len + 1);
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
                N[i] = 0;
            else
            {
                int p = N[i - 1];
                while (p && s[p] != s[i])
                    p = N[p - 1];
                if (s[p] == s[i])
                    N[i] = p + 1;
                else
                    N[i] = 0;
            }
        }
        int ans = 1;
        for (int i = 1; i <= len; i++)
        {
            int cnt = 0;
            for (int t = N[i - 1]; t; t = N[t - 1])
            {
                if (t <= i / 2)
                {
                    cnt++;
                }
            }
            ans *= (cnt + 1);
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}