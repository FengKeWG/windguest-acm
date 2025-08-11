#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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
int cnt[N], ans;
int tot = 1, np = 1;
int fa[N], ch[N][26], len[N];
vector<int> e[N];

void ext(int c)
{
    int p = np;
    np = ++tot;
    len[np] = len[p] + 1;
    cnt[np] = 1;
    for (; p && !ch[p][c]; p = fa[p])
        ch[p][c] = np;
    if (p == 0)
        fa[np] = 1;
    else
    {
        int q = ch[p][c];
        if (len[q] == len[p] + 1)
            fa[np] = q;
        else
        {
            int nq = ++tot;
            len[nq] = len[p] + 1;
            fa[nq] = fa[q];
            fa[q] = nq;
            fa[np] = nq;
            for (; p && ch[p][c] == q; p = fa[p])
                ch[p][c] = nq;
            memcpy(ch[nq], ch[q], sizeof ch[q]);
        }
    }
}

void dfs(int u)
{
    for (auto &v : e[u])
    {
        ans += len[v] - len[u];
        dfs(v);
    }
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
        ext(s[i] - 'a');
    for (int i = 2; i <= tot; i++)
        e[fa[i]].push_back(i);
    // cout << len[7] << endl;
    dfs(1);
    cout << ans << endl;
    return 0;
}