#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 15
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
int a[MAXN];
int f[MAXN][10];

void pre()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= MAXN; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int cal(int n)
{
    if (!n)
        return 0;
    int res = 0;
    int cnt = 0;
    while (n)
    {
        a[++cnt] = n % 10;
        n /= 10;
    }
    int last = INF;
    for (int i = cnt; i > 0; i--)
    {
        int now = a[i];
        for (int j = (i == cnt); j < now; j++)
        {
            if (abs(last - j) >= 2)
                res += f[i][j];
        }
        if (abs(now - last) < 2)
            break;
        last = now;
        if (i == 1)
            res++;
    }
    for (int i = 1; i < cnt; i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    while (cin >> l >> r)
        cout << cal(r) - cal(l - 1) << endl;
    return 0;
}