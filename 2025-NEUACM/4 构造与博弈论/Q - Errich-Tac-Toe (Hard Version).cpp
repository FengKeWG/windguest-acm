#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 305
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
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

int a[N][N];
int cnt[3][3];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        memset(cnt, 0, sizeof cnt);
        string s;
        int n = read();
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            for (int j = 1; j <= n; j++)
            {
                if (s[j - 1] == 'X')
                {
                    a[i][j] = 1;
                    k++;
                }
                else if (s[j - 1] == 'O')
                {
                    a[i][j] = 2;
                    k++;
                }
                else
                    a[i][j] = 0;
                cnt[(i + j) % 3][a[i][j]]++;
            }
        }
        int res = 0;
        bool ok = 0;
        for (int d1 = 0; d1 < 3; d1++)
        {
            for (int d2 = 0; d2 < 3; d2++)
            {
                if (d1 == d2)
                    continue;
                if (cnt[d1][1] + cnt[d2][2] <= k / 3)
                {
                    for (int i = 1; i <= n; i++)
                        for (int j = 1; j <= n; j++)
                        {
                            if ((i + j) % 3 == d1 && a[i][j] == 1)
                            {
                                a[i][j] = 2;
                                res++;
                            }
                            else if ((i + j) % 3 == d2 && a[i][j] == 2)
                            {
                                a[i][j] = 1;
                                res++;
                            }
                        }
                    ok = 1;
                    break;
                }
            }
            if (ok)
                break;
        }
        // cout << res << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1)
                    cout << 'X';
                else if (a[i][j] == 2)
                    cout << 'O';
                else
                    cout << '.';
            }
            cout << endl;
        }
    }
    return 0;
}