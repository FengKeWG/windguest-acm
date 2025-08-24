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

int a[N][N];
int b[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = read();
                b[i][j] = 0;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (b[i][j])
                    continue;
                if (a[i][j] <= a[j][i])
                {
                    b[i][j] = a[i][j];
                    b[j][i] = a[j][i];
                }
                else
                {
                    b[i][j] = a[j][i];
                    b[j][i] = a[i][j];
                }
            }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << b[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}