#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

int n, m;
vector<vector<int>> a;
int cnt, ans;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, bool &found)
{
    if (a[x][y] > 1 && !found)
    {
        found = 1;
        ans++;
    }
    a[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > m)
            continue;
        if (a[nx][ny])
            dfs(nx, ny, found);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    a.resize(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j])
            {
                bool found = 0;
                cnt++;
                dfs(i, j, found);
            }
    cout << cnt << " " << ans << endl;
    return 0;
}