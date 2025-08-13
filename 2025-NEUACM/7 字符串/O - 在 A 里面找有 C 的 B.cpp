#include <bits/stdc++.h>
// #define int long long
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

int n, idx;
char s[N];
int ch[N][26];
int ne[N];
vector<int> pos[N];
bool vis[M];

void insert(char *s, int id)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    pos[p].push_back(id);
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

void query(char *s)
{
    for (int k = 0, i = 0; s[k]; k++)
    {
        i = ch[i][s[k] - 'a'];
        for (int j = i; j; j = ne[j])
            if (pos[j].size())
                for (auto &x : pos[j])
                    vis[x] = 1;
    }
}

char p[N], r[N], t[N];
int Ne[N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n = read();
        memset(vis, 0, sizeof vis);
        for (int i = 0; i <= idx; i++)
        {
            memset(ch[i], 0, sizeof ch[i]);
            ne[i] = 0;
            pos[i].clear();
        }
        idx = 0;
        scanf("%s%s", p, r);
        int m = strlen(r);
        Ne[0] = 0;
        for (int i = 1, j = 0; i < m; i++)
        {
            while (j && r[i] != r[j])
                j = Ne[j - 1];
            if (r[i] == r[j])
                ++j;
            Ne[i] = j;
        }
        for (int k = 1; k <= n; k++)
        {
            scanf("%s%s", s, t);
            int l = strlen(t);
            bool can = 0;
            for (int i = 0, j = 0; i < l; i++)
            {
                while (j && t[i] != r[j])
                    j = Ne[j - 1];
                if (t[i] == r[j])
                    ++j;
                if (j == m)
                {
                    can = 1;
                    break;
                }
            }
            if (can)
                insert(s, k);
        }
        build();
        query(p);
        for (int i = 1; i <= n; i++)
            if (vis[i])
                cout << i << ' ';
        cout << endl;
    }
    return 0;
}