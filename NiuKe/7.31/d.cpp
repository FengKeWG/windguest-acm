#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
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

int a[N], b[N];
int c[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = 1;
    for (int i = 0; i <= m; i++)
        c[i] = 1;
    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i <= m; i++)
        {
            c[i] += c[i - 1];
            b[i] = c[i];
        }
        for (int i = 1; i <= m; i++)
        {
            c[i] = 0;
            for (int j = 0; j <= i; j++)
                c[i] += b[j] * a[i + 1 - j];
            cout << c[i] << endl;
        }
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
    }
    cout << c[m] << endl;
    return 0;
}