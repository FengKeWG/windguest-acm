#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
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

char s[N];
int n;
int ne[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (scanf("%s", s + 1) && s[1] != '.')
    {
        n = strlen(s + 1);
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j && s[i] != s[j + 1])
                j = ne[j];
            if (s[i] == s[j + 1])
                j++;
            ne[i] = j;
        }
        int cnt = 0;
        int dif = n - ne[n];
        for (int j = n; j; j = ne[j])
        {
            // cout << j << ' ' << ne[j] << endl;
            cnt++;
            if (j - ne[j] != dif)
                break;
        }
        if (n % cnt)
            cnt = 1;
        cout << cnt << endl;
    }
    return 0;
}