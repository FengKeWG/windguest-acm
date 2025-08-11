#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
char p[205][N];
int ch[N][26];
int ne[N], cnt[N];
int pos[N];
vector<int> ord;

void insert(char *s, int k)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    pos[k] = p;
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
        ord.push_back(u);
        for (int i = 0; i < 26; i++)
        {
            int v = ch[u][i];
            if (v)
            {
                ne[v] = ch[ne[u]][i];
                q.push(v);
            }
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
        cnt[i]++;
    }
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        insert(p[i], i);
    }
    build();
    for (int i = 1; i <= n; i++)
        query(p[i]);
    for (int i = ord.size() - 1; i >= 0; i--)
        cnt[ne[ord[i]]] += cnt[ord[i]];
    for (int i = 1; i <= n; i++)
        cout << cnt[pos[i]] << endl;
    return 0;
}