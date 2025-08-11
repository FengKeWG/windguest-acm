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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    const int nn = log2(n);
    vector<int> a(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(nn + 1));
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        f[i][0] = a[i];
    }
    for (int j = 1; j <= nn; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--)
    {
        int l = read(), r = read();
        int k = log2(r - l + 1);
        cout << max(f[l][k], f[r - (1 << k) + 1][k]) << endl;
    }
    return 0;
}