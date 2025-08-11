#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1000005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
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

int c[MAXN];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s, t;
    int n;
    cin >> n >> s >> t;
    if (s[0] != t[0] || s.size() != t.size())
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0, k = 0, sum = 0;
    for (int i = n - 1, j = n - 1; i >= 0; i--)
    {
        sum += c[i + k];
        if (j > i || t[i] != s[j])
        {
            while (j >= 0 && (j > i || t[i] != s[j]))
                j--;
            if (j == i)
                continue;
            if (j < 0)
            {
                cout << -1 << endl;
                return 0;
            }
            k++, sum++;
            c[i + k - 1] = 0, c[j + k - 1]--;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
