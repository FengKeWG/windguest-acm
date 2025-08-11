#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
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

char s[N], a[N];
int d[N], L[N], R[N];
int n, k;
int l = -1, r = -1;
int ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> (a + 1);
    n = strlen(a + 1);
    a[0] = '$';
    for (int i = 0; i <= n; i++)
        s[++k] = a[i], s[++k] = '#';
    n = k;
    cout << (s + 1) << endl;
    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= r)
            d[i] = max(d[r - i + l], r - i + 1);
        while (s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
        L[i - d[i] + 1] = max(L[i - d[i] + 1], d[i] - 1);
        R[i + d[i] - 1] = max(R[i + d[i] - 1], d[i] - 1);
    }
    for (int i = 1; i <= n; i += 2)
        L[i] = max(L[i], L[i - 2] - 2);
    for (int i = n; i >= 1; i -= 2)
        R[i] = max(R[i], R[i + 2] - 2);
    for (int i = 1; i <= n; i += 2)
        if (L[i] && R[i])
            ans = max(ans, L[i] + R[i]);
    cout << ans << endl;
    return 0;
}