#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 20005
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

char p[N];
char s[1005][25];
int ch[N][26];
int idx;
int cnt[N];
int pos[N];
int ans[N];

void insert(char *s, int k)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
        pos[p] = k;
    }
}

void dfs(int u, int d)
{
    for (int i = 0; i < 26; i++)
    {
        int j = ch[u][i];
        if (j)
        {
            if (cnt[j] == 1)
            {
                ans[pos[j]] = d + 1;
                continue;
            }
            dfs(j, d + 1);
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int i = 0;
    while (cin >> s[++i])
        insert(s[i], i);
    int n = i - 1;
    dfs(0, 0);
    for (int k = 1; k <= n; k++)
        if (!ans[k])
            ans[k] = strlen(s[k]);
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << ' ';
        for (int j = 0; s[i][j]; j++)
        {
            cout << s[i][j];
            if (j + 1 == ans[i])
                break;
        }
        cout << endl;
    }
    return 0;
}