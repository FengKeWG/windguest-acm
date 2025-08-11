#include <bits/stdc++.h>
#define int long long
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

int n, idx;
char s[N];
int ch[N][26];
int ne[N], cnt[N];

void insert(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    cnt[p]++;
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int v = ch[u][i];
            if (v)
                ne[v] = ch[ne[u]][i], q.push(v);
            else
                ch[u][i] = ch[ne[u]][i];
        }
    }
}

int query(char *s)
{
    int ans = 0;
    for (int k = 0, i = 0; s[k]; k++)
    {
        i = ch[i][s[k] - 'a'];
        for (int j = i; j && ~cnt[j]; j = ne[j])
            ans += cnt[j], cnt[j] = -1;
    }
    return ans;
}

char p[N], r[N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        scanf("%s%s", p + 1, r + 1);
    }
    return 0;
}