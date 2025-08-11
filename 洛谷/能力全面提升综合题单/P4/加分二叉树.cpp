#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 35
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
#define int128 __int128
using namespace std;
void print(int128 x)
{
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
int n;
int f[N][N];
int root[N][N];
void print(int l, int r)
{
    if (l > r)
        return;
    cout << root[l][r] << " ";
    if (l >= r)
        return;
    print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            f[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        f[i][i] = read(), root[i][i] = i;
    for (int len = 2; len <= n; len++)
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k <= r; k++)
            {
                int left = (k == l) ? 1 : f[l][k - 1];
                int right = (k == r) ? 1 : f[k + 1][r];

                if (f[l][r] < left * right + f[k][k])
                {
                    f[l][r] = left * right + f[k][k];
                    root[l][r] = k;
                }
            }
        }

    cout << f[1][n] << endl;
    print(1, n);
    return 0;
}