#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 3000005
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

int get(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    else
        return c - '0' + 52;
}

int ch[N][65];
int cnt[N];
char s[N];
int idx;

void insert(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = get(s[i]);
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
    }
}

int query(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = get(s[i]);
        if (!ch[p][j])
            return 0;
        p = ch[p][j];
    }
    return cnt[p];
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        for (int i = 0; i <= idx; i++)
            for (int j = 0; j < 130; j++)
                ch[i][j] = 0;
        for (int i = 0; i <= idx; i++)
            cnt[i] = 0;
        idx = 0;
        int n, q;
        cin >> n >> q;
        while (n--)
        {
            scanf("%s", s);
            insert(s);
        }
        while (q--)
        {
            scanf("%s", s);
            cout << query(s) << endl;
        }
    }
    return 0;
}