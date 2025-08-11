#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

int T;
int n, m, k;
string s;
vector<vector<int>> a, vis;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool dfs(int r, int c)
{
    vis[r][c] = 1;
    if (c == m)
        return 1;
    int cnt = 0;
    bool can = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 1 || nr > n || nc < 1 || nr > m)
            continue;
        if (vis[nr][nc])
            continue;
        if (a[nr][nc] == 1)
            continue;
        if (dfs(nr, nc))
        {
            a[r][c] = -1;
            can = 1;
        }
    }
    if (can)
        return 1;
    else
        return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        a.assign(n + 1, vector<int>(m + 1, 0));
        vis.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                a[i][j + 1] = s[j] - '0';
            }
        }
        dfs(1, 1);
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << a[i][j] << ' ';
        //     cout << endl;
        // }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //         cout << vis[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;
        bool yes = 0;
        for (int i = 1; i <= n; i++)
        {
            bool is = 0;
            int cnt = 0;
            for (int j = m - 1; j > 1; j--)
            {
                if (a[i][j] == 0 && !vis[i][j])
                    continue;
                if (a[i][j] == -1)
                    continue;
                if (a[i][j] == 1)
                {
                    is = 1;
                    cnt = 0;
                    continue;
                }
                if (is)
                {
                    cnt++;
                    if (cnt >= k)
                    {
                        yes = 1;
                        break;
                    }
                }
            }
            if (yes)
                break;
        }
        if (yes)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}