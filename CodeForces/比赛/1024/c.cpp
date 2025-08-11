#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1005
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

int T, n;
int a[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        int x = (n - 1) / 2;
        int y = (n - 1) / 2;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;
        int step = 1;
        int num = 0;
        if (0 <= x && x < n && 0 <= y && y < n)
        {
            a[x][y] = num++;
        }
        while (num < n * n)
        {
            for (int turn = 0; turn < 2 && num < n * n; turn++)
            {
                for (int s = 0; s < step && num < n * n; s++)
                {
                    x += dx[dir];
                    y += dy[dir];
                    if (0 <= x && x < n && 0 <= y && y < n)
                    {
                        a[x][y] = num++;
                    }
                }
                dir = (dir + 1) % 4;
            }
            step++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << (j + 1 == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}