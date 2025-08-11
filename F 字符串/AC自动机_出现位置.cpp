#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 500005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int get(char c)
{
    if (isdigit(c))
        return c - '0';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 26;
}

int m;
int n, idx;
int ne[N];
string s;
int ch[N][65];
vector<int> ids[N];
string a[M];
int pos[M];

void insert(string s, int id)
{
    int p = 0;
    for (auto &c : s)
    {
        int j = get(c);
        if (!ch[p][c])
            ch[p][j] = ++idx;
        p = idx;
    }
    ids[p].push_back(id);
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 64; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 64; i++)
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

void query()
{
    memset(pos, -1, sizeof(pos));
    for (int k = 0, i = 0; k < s.size(); k++)
    {
        i = ch[i][get(s[k])];
        for (int j = i; j; j = ne[j])
        {
            for (auto &id : ids[j])
            {
                if (pos[id] != -1)
                    continue;
                pos[id] = k - a[id].size() + 1;
            }
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string t;
        cin >> t;
        insert(t, i);
    }
    build();
    query();
    for (int i = 1; i <= m; i++)
        cout << pos[i] << ' ';
    return 0;
}