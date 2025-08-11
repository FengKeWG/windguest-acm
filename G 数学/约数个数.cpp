#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
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

/*
n = pi^ai 的连乘
则d[n] = (ai+1) 的连乘
*/

bool vis[N];
int p[N], cnt;
int d[N], a[N]; // i的最小质因子的次数

void get(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            p[++cnt] = i;
            a[i] = 1, d[i] = 2;
        }
        for (int j = 1; p[j] * i <= n; j++)
        {
            int m = p[j] * i;
            vis[m] = 1;
            if (i % j == 0)
            {
                a[m] = a[i] + 1;
                d[m] = d[i] / a[m] * (a[m] + 1);
                break;
            }
            else
            {
                a[m] = 1, d[m] = d[i] * 2;
            }
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}