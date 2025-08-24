#include <bits/stdc++.h>
#define inf LLONG_MAX / 2
#define endl '\n'
#define pii pair<int, int>
#define N 105
using namespace std;

int a[N][N];
vector<pii> v;

signed main()
{
    int nn, mm, q;
    cin >> nn >> mm >> q;
    for (int t = 1; t <= q; t++)
    {
        string s;
        int n, m;
        cin >> n >> m;
        v.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= m; j++)
                if (s[j - 1] == '*')
                    v.push_back({i, j});
        }
        int R, C;
        bool can = 0;
        for (int i = 1; i <= nn; i++)
        {
            for (int j = 1; j <= mm; j++)
            {
                bool br = 0;
                int dr = v[0].first - i;
                int dc = v[0].second - j;
                for (auto &[x, y] : v)
                {
                    // cout << x << ' ' << y << ' ';
                    int r = x - dr;
                    int c = y - dc;
                    // cout << r << ' ' << c << endl;
                    if (r < 1 || r > nn || c < 1 || c > mm)
                    {
                        br = 1;
                        break;
                    }
                    if (a[r][c] != 0)
                    {
                        br = 1;
                        break;
                    }
                }
                if (!br)
                {
                    can = 1;
                    // cout << "can!" << endl;
                    R = i, C = j;
                    int dr = v[0].first - i;
                    int dc = v[0].second - j;
                    for (auto &[x, y] : v)
                    {
                        int r = x - dr;
                        int c = y - dc;
                        a[r][c] = 1;
                    }
                    break;
                }
            }
            if (can)
                break;
        }
        // cout << v[0].first << ' ' << v[0].second << endl;
        if (can)
            cout << R << ' ' << C << endl;
        else
            cout << -1 << ' ' << -1 << endl;
    }
    return 0;
}