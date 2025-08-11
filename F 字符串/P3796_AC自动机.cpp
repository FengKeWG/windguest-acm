#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 10510
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

struct node
{
    int idx;
    int cnt;
    char s[155];
};

bool cmp(const node &a, const node &b)
{
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    else
        return a.idx < b.idx;
}

int n, idx;
char s[1000005];
int ne[MAXN], cnt[MAXN];
int ch[MAXN][26];
node ans[MAXN];

void insert(char *s, int i)
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
    strcpy(ans[idx].s, s);
    ans[idx].idx = i;
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
            if (cnt[j])
                ans[j].cnt += cnt[j];
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n && n != 0)
    {
        idx = 0;
        memset(ch, 0, sizeof(ch));
        memset(ne, 0, sizeof(ne));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < MAXN; i++)
        {
            ans[i].cnt = 0;
            ans[i].s[0] = '\0';
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            insert(s, i);
        }
        build();
        cin >> s;
        query(s);
        sort(ans, ans + MAXN, cmp);
        int mx = ans[0].cnt;
        cout << mx << endl;
        for (int i = 0; i < 155; i++)
            if (ans[i].cnt == mx)
                cout << ans[i].s << endl;
    }
    return 0;
}