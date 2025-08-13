#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX / 2
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

int ch[N][3];
int idx;
char s[N];
int ne[N];
int cnt[N];

void insert(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'A';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    cnt[p]++;
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 3; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int v = ch[u][i];
            if (v)
            {
                ne[v] = ch[ne[u]][i];
                cnt[v] += cnt[ne[v]];
                q.push(v);
            }
            else
                ch[u][i] = ch[ne[u]][i];
        }
    }
}

int f[2][N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        insert(s);
    }
    build();
    for (int i = 0; i <= idx; i++)
        f[0][i] = -inf;
    f[0][0] = 0;
    int now = 0, nxt = 1;
    for (int r = 1; r <= k; r++)
    {
        for (int i = 0; i <= idx; i++)
            f[nxt][i] = -inf;
        for (int i = 0; i <= idx; i++)
        {
            if (f[now][i] == -inf)
                continue;
            for (int j = 0; j < 3; j++)
            {
                int v = ch[i][j];
                f[nxt][v] = max(f[nxt][v], f[now][i] + cnt[v]);
            }
        }
        now ^= 1, nxt ^= 1;
    }
    int ans = -inf;
    for (int i = 0; i <= idx; i++)
        ans = max(ans, f[now][i]);
    cout << ans << endl;
    return 0;
}