#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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

int pr[N], cnt;
bool vis[N];
int f[N];

void get(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            pr[cnt++] = i;
            f[i] = cnt;
        }
        for (int j = 0; pr[j] <= n / i; j++)
        {
            int tmp = pr[j] * i;
            vis[tmp] = 1;
            if (tmp & 1)
                f[tmp] = f[pr[j]];
            if (i % pr[j] == 0)
                break;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    get(N - 1);
    f[1] = 1, f[2] = 0;
    int t = read();
    while (t--)
    {
        int n = read();
        int res = 0;
        while (n--)
        {
            int m = read();
            res ^= f[m];
        }
        cout << (res ? "Alice" : "Bob") << endl;
    }
    return 0;
}