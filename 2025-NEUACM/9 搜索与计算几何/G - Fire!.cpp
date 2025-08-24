#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define N 1005
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

char a[N][N];
bool vis[N][N];
int tf[N][N];
int t[N][N];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int R, C;
        cin >> R >> C;
        string s;
        queue<pii> q1, q2;
        for (int i = 1; i <= R; i++)
        {
            cin >> s;
            for (int j = 1; j <= C; j++)
            {
                a[i][j] = s[j - 1];
                tf[i][j] = inf;
                t[i][j] = inf;
                if (a[i][j] == 'J')
                {
                    t[i][j] = 0;
                    q1.push({i, j});
                }
                else if (a[i][j] == 'F')
                {
                    q2.push({i, j});
                    tf[i][j] = 0;
                }
            }
        }
        int ans = -1;
        while (q2.size())
        {
            auto [r, c] = q2.front();
            q2.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 1 || nr > R || nc < 1 || nc > C)
                    continue;
                if (a[nr][nc] == '#')
                    continue;
                if (tf[nr][nc] <= tf[r][c] + 1)
                    continue;
                tf[nr][nc] = tf[r][c] + 1;
                q2.push({nr, nc});
            }
        }
        while (q1.size() && !~ans)
        {
            auto [r, c] = q1.front();
            q1.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int nt = t[r][c] + 1;
                if (nr < 1 || nr > R || nc < 1 || nc > C)
                {
                    ans = nt;
                    break;
                }
                if (a[nr][nc] == '#')
                    continue;
                if (tf[nr][nc] <= nt)
                    continue;
                if (t[nr][nc] <= nt)
                    continue;
                t[nr][nc] = nt;
                q1.push({nr, nc});
            }
        }
        if (~ans)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}