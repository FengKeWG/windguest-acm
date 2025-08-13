#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 20
#define INF LLONG_MAX
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

int f[1 << 20];

int sg(int m)
{
    if (f[m] != -1) // 记忆化
        return f[m];
    set<int> s;
    for (int i = 0; i < 19; i++) // 所有后续状态加入s
    {
        if (!(m & 1 << i))
            continue;
        if (!(m & 1 << i + 1))
            s.insert(sg((m ^ (1 << i)) | (1 << i + 1)));
        else
        {
            int k = i + 1;
            while (k < 20 && (m & (1 << k)))
                k++;
            if (k < 20)
                s.insert(sg((m ^ (1 << i)) | (1 << k)));
        }
    }
    for (int i = 0;; i++) // 返回mex并记忆化
        if (!s.count(i))
            return f[m] = i;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(f, -1, sizeof f);
    int T = read();
    while (T--)
    {
        int n = read();
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = read();
            int m = 0;
            for (int j = 0; j < k; j++)
            {
                int x = read();
                m |= (1 << (x - 1));
            }
            res ^= sg(m);
        }
        cout << (res ? "YES\n" : "NO\n");
    }
    return 0;
}