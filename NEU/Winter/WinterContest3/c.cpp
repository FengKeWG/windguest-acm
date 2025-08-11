#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<vector<int>> f(21, vector<int>(21));
        int ans = 0;
        bool can = 1;
        for (int i = 0; i < n; i++)
        {
            if (b[i] < a[i])
            {
                cout << -1 << endl;
                can = 0;
                break;
            }
            else
                f[a[i] - 'a'][b[i] - 'a']++;
        }
        if (!can)
            continue;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (i != j && f[i][j])
                {
                    ans++;
                    for (int k = j + 1; k < 20; k++)
                    {
                        if (f[i][k])
                        {
                            f[j][k] += f[i][k];
                            f[i][k] = 0;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}