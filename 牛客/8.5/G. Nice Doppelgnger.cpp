#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
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

bool is[2 * N];
int a[2 * N];
int tot;
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 1000; i++)
        is[i * i] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        if (is[i])
            continue;
        for (int j = 1; j <= i; j++)
        {
            if (i * a[j] > 1000000)
                break;
            is[i * a[j]] = 1;
        }
        a[++tot] = i;
    }
    // cout << tot << endl;
    int T = read();
    while (T--)
    // for (n = 2; n <= 1000; n += 2)
    {
        n = read();
        for (int i = 1; i <= n / 2; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}