#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 22000010
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

char s[N], a[N];
int d[N];

void getd(char *s, int n)
{
    d[1] = 1;
    int l = -1, r = -1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= r)
            d[i] = min(d[r - i + l], r - i + 1);
        while (s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s", a + 1);
    int n = strlen(a + 1), k = 0;
    a[0] = '$';
    for (int i = 0; i <= n; i++)
        s[++k] = a[i], s[++k] = '#';
    n = k;
    getd(s, n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, d[i] - 1);
    cout << ans << endl;
    return 0;
}