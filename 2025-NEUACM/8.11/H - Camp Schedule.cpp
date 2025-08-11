#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 500005
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

char s[N], p[N];
int m, n;
int ne[N];
int cnt[2];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s%s", s + 1, p + 1);
    m = strlen(s + 1), n = strlen(p + 1);
    for (int i = 1; s[i]; i++)
        cnt[s[i] - '0']++;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    int i = 1;
    while (1)
    {
        if (i == n + 1)
            i = ne[n] + 1;
        if (cnt[p[i] - '0'])
        {
            cout << p[i];
            cnt[p[i] - '0']--;
            i++;
        }
        else
            break;
    }
    for (int i = 0; i <= 1; i++)
        while (cnt[i]--)
            cout << i;
    return 0;
}