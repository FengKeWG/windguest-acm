#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 12
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

int n, k;
int s[1 << N];
int num[1 << N];
int cnt;
int f[N][1 << N][N * N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 0; i < 1 << n; i++)
    {
        if (i & i << 1)
            continue;
        s[++cnt] = i;
        for (int j = 0; j < n; j++)
            num[i] += (i >> j & 1);
    }
    f[0][1][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int a = 1; a <= cnt; a++)
            for (int b = 1; b <= cnt; b++)
                for (int j = 0; j <= min(i * n, k); j++)
                {
                    if (s[a] & s[b] || s[a] & s[b] << 1 || s[a] & s[b] >> 1)
                        continue;
                    if (j - num[s[a]] < 0)
                        continue;
                    f[i][a][j] += f[i - 1][b][j - num[s[a]]];
                }
    cout << f[n + 1][1][k];
    return 0;
}