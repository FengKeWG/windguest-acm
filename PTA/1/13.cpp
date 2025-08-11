#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 105
#define M 5005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[x].l + t[x].x) >> 1)
#define ls (x << 1)
#define rs (x << 1 | 1)
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
    char y = getchar();
    while (y < '0' || y > '9')
    {
        if (y == '-')
            f = -1;
        y = getchar();
    }
    while (y >= '0' && y <= '9')
    {
        x = (x << 1) + (x << 3) + (y ^ 48);
        y = getchar();
    }
    return x * f;
}

struct node
{
    int x, y;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, k;
int a[N][N];
int d[N][N];
node st[M];
node ed;

signed main()
{
    m = read(), n = read();
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = read();
            if (a[i][j] == 2)
                ed = {i, j};
        }
    memset(d, -1, sizeof d);
    queue<pair<node, int>> q;
    q.push({ed, 0});
    d[ed.x][ed.y] = 0;
    while (q.size())
    {
        auto now = q.front();
        q.pop();
        node pos = now.first;
        int t = now.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = pos.x + dx[i];
            int ny = pos.y + dy[i];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n &&
                a[nx][ny] != 0 &&
                d[nx][ny] == -1)
            {
                d[nx][ny] = t + 1;
                q.push({{nx, ny}, t + 1});
            }
        }
    }
    k = read();
    for (int i = 1; i <= k; i++)
        st[i].y = read(), st[i].x = read();
    map<int, vector<int>> mp;
    for (int i = 1; i <= k; i++)
    {
        int x = st[i].x;
        int y = st[i].y;
        int t = d[x][y];
        if (~t)
            mp[t].push_back(i);
    }
    bool found = 0;
    for (auto const &[t, x] : mp)
    {
        if (x.size() == 1)
        {
            cout << x[0] << " " << t << endl;
            found = 1;
            break;
        }
    }
    if (!found)
        printf("No winner.\n");
    return 0;
}