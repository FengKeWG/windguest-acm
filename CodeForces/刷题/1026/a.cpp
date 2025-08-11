#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

int T;
int n;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        int ans = 0;
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }
        sort(a + 1, a + 1 + n);
        int j1 = -1, o1 = -1, j2 = -1, o2 = -1;
        for (int i = 1; i <= n; i++)
        {
            if (j1 == -1 && a[i] & 1)
                j1 = i;
            else if (o1 == -1 && !(a[i] & 1))
                o1 = i;
        }
        for (int i = n; i >= 1; i--)
        {
            if (j2 == -1 && a[i] & 1)
                j2 = i;
            else if (o2 == -1 && !(a[i] & 1))
                o2 = i;
        }
        cout << min(j1 - 1 + n - j2, o1 - 1 + n - o2) << endl;
    }
    return 0;
}