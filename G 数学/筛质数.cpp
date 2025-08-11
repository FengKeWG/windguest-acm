#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100000005
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

bool vis[N];
int pr[N];
int cnt;

void get(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[++cnt] = i;
            for (int j = i * i; j <= n; j += i) // 注意从i*i开始
                vis[j] = 1;
        }
    }
}

void get2(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pr[++cnt] = i;
        for (int j = 1; pr[j] * i <= n; j++)
        {
            vis[pr[j] * i] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    get2(n);
    for (int i = 1; i <= cnt; i++)
        cout << pr[i] << ' ';
    return 0;
}