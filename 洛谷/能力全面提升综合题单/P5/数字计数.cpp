#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 25
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

int l, r;
int a[N];
int f[10][N][N];
int p10[N];

int cal(int m, int n)
{
    if (!n && m)
        return 0;
    if (!n && !m)
        return 1;
    int cnt = 0;
    while (n)
    {
        a[++cnt] = n % 10;
        n /= 10;
    }
    int res = 0;
    int cnt2 = 0;
    for (int i = cnt; i > 0; i--)
    {
        int now = a[i];
        for (int j = 0; j < now; j++)
        {
            res += f[m][i][j];
            res += cnt2 * p10[i - 1];
            //  cout << i << " " << j << " " << res << endl;
        }
        if (i == 1)
        {
            res += cnt2;
            if (now == m)
                res++;
        }
        if (now == m)
            cnt2++;
    }
    // cout << res << endl;
    if (m == 0)
    {
        for (int i = 2; i <= cnt; i++)
        {
            if (i == 2)
                res -= (cnt - 1) * 10;
            else
                res -= 9 * p10[i - 2] * (cnt - i + 1);
        }
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    p10[0] = 1;
    for (int i = 1; i < N; i++)
        p10[i] = p10[i - 1] * 10;
    for (int m = 0; m <= 9; m++)
    {
        for (int i = 0; i <= 9; i++)
            f[m][1][i] = (i == m);
        for (int i = 2; i < N; i++)
        {
            int sum = 0;
            for (int k = 0; k <= 9; k++)
                sum += f[m][i - 1][k];
            for (int j = 0; j <= 9; j++)
            {
                f[m][i][j] = sum;
                if (j == m)
                    f[m][i][j] += p10[i - 1];
            }
        }
    }
    // cout << f[0][2][0] << endl;
    // cout << cal(0, 0) << endl;
    // cout << cal(0, 99) << endl;
    l = read(), r = read();
    for (int i = 0; i <= 9; i++)
        cout << cal(i, r) - cal(i, l - 1) << " ";
    return 0;
}