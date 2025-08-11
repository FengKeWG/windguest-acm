#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 15
#define MOD 1000000007
#define eps 1e-6
#define INF LLONG_MAX
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

int n, m;
bool st[1 << 15];
int f[15][1 << 15];
// 按列分状态
// 状态中1表示这一格会往右边突出去，0表示不会往右边突出去

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (cin >> n >> m && n && m)
    {
        for (int i = 0; i < 1 << n; i++) // 两个状态|之后，连续的奇数个0，这个状态就不合法，说明出现一个单独的空格了，偶数的合法，因为可以一列竖着，另一列也竖着。
        {
            st[i] = true;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        st[i] = false;
                        break;
                    }
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                st[i] = false;
        }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int a = 0; a < 1 << n; a++)
            {
                for (int b = 0; b < 1 << n; b++)
                {
                    if (st[a | b] && !(a & b))
                    {
                        f[i][a] += f[i - 1][b];
                    }
                }
            }
        }
        cout << f[m][0] << endl;
    }
    return 0;
}