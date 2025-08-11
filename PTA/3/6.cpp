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

char s[N], p[N];
string ans1, ans2;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s%s", s + 1, p + 1);
    for (int i = 2; s[i]; i++)
    {
        if (s[i] % 2 == s[i - 1] % 2)
        {
            ans1 += max(s[i], s[i - 1]);
        }
    }
    for (int i = 2; p[i]; i++)
    {
        if (p[i] % 2 == p[i - 1] % 2)
        {
            ans2 += max(p[i], p[i - 1]);
        }
    }
    if (ans1 == ans2)
        cout << ans1;
    else
        cout << ans1 << endl
             << ans2;
    return 0;
}