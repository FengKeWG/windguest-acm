#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 55
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

int n;
int a[N][N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    int r = 1, c = n / 2 + 1;
    a[r][c] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (r == 1 && c != n)
            r = n, c++;
        else if (c == n && r != 1)
            r--, c = 1;
        else if (r == 1 && c == n)
            r++;
        else if (!a[r - 1][c + 1])
            r--, c++;
        else
            r++;
        a[r][c] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << (j == n ? '\n' : ' ');
    return 0;
}