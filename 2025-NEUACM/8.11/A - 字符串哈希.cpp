#include <bits/stdc++.h>
#define int unsigned long long
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

int P = 131;
int p[N], h[N];
char s[N];
int ans[N];

int cal(char *s, int n)
{
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = h[i - 1] * P + s[i];
    return h[n];
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        int m = strlen(s + 1);
        ans[i] = cal(s, m);
    }
    sort(ans + 1, ans + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (ans[i] != ans[i - 1])
            cnt++;
    cout << cnt << endl;
    return 0;
}