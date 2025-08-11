#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

int h, w;
int ans = INF;

void dfs(int y, int x, int cnt, int res, vector<vector<int>> a)
{
    int n = 1;
    for (n = 1; n <= 10; n++)
    {
        if (y + n > h || x + n > w)
            break;
        bool br = 0;
        for (int i = y; i <= y + n; i++)
        {
            for (int j = x; j <= x + n; j++)
            {
                if (a[i][j] == 0)
                {
                    br = 1;
                    break;
                }
            }
            if (br)
                break;
        }
        if (br)
            break;
    }
    n--;
    for (int i = y; i <= y + n; i++)
    {
        for (int j = x; j <= x + n; j++)
        {
            if (a[i][j] == 1)
                res--;
            a[i][j] = 2;
        }
    }
    // cout << "n: " << n << " res: " << res << endl;
    cnt++;
    if (res == 0)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (a[i][j] == 1)
            {
                // cout << i << " " << j << endl;
                dfs(i, j, cnt, res, a);
            }
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> w >> h && h != 0 && w != 0)
    {
        ans = INF;
        int res = 0;
        vector<vector<int>> a(h + 1, vector<int>(w + 1));
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 1)
                    res++;
            }
        int y, x;
        for (int i = 1; i <= h; i++)
        {
            bool br = 0;
            for (int j = 1; j <= w; j++)
            {
                if (a[i][j] == 1)
                {
                    y = i;
                    x = j;
                    br = 1;
                    break;
                }
            }
            if (br)
                break;
        }
        dfs(y, x, 0, res, a);
        cout << ans << endl;
    }
    return 0;
}