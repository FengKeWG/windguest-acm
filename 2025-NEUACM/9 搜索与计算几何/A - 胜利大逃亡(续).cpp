#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 30
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

int n, m, t;
char a[N][N];
bool vis[N][N][1 << 10];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct node
{
    int r, c, m, d;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m >> t)
    {
        int sr = -1, sc = -1, er = -1, ec = -1;
        string s;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = s[j - 1];
                if (s[j - 1] == '@')
                    sr = i, sc = j;
                else if (s[j - 1] == '^')
                    er = i, ec = j;
            }
        }

        memset(vis, 0, sizeof vis);
        queue<node> q;
        q.push({sr, sc, 0, 0});
        vis[sr][sc][0] = 1;
        int ans = -1;
        while (q.size())
        {
            auto [r, c, ma, d] = q.front();
            q.pop();
            if (r == er && c == ec)
            {
                ans = d;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 1 || nr > n || nc < 1 || nc > m)
                    continue;
                char c = a[nr][nc];
                if (c == '*')
                    continue;
                int nm = ma;
                if (c >= 'a' && c <= 'j')
                    nm |= (1 << (c - 'a'));
                if (c >= 'A' && c <= 'J')
                    if (((ma >> c - 'A') & 1ll) == 0)
                        continue;
                if (!vis[nr][nc][nm])
                {
                    vis[nr][nc][nm] = 1;
                    q.push({nr, nc, nm, d + 1});
                }
            }
        }
        if (~ans && ans < t)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}