#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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
    int s[2];
    int w;
    int pr;
    int fa;
    void init(int w1, int pr1, int fa1)
    {
        w = w1, pr = pr1, fa = fa1;
        s[0] = s[1] = 0;
    }
} t[N];

int n, idx, root;

void rot(int x)
{
    int y = t[x].fa, z = t[y].fa;
    int k = t[y].s[1] == x;
    t[y].s[k] = t[x].s[k ^ 1];
    if (t[x].s[k ^ 1])
        t[t[x].s[k ^ 1]].fa = y;
    t[x].s[k ^ 1] = y;
    t[y].fa = x;
    if (z)
        t[z].s[t[z].s[1] == y] = x;
    else
        root = x;
    t[x].fa = z;
}

void insert(int w, int p)
{
    int x = root, fa = 0;
    while (x && t[x].w != w)
    {
        fa = x;
        x = t[x].s[w > t[x].w];
    }
    if (x)
        return;
    x = ++idx;
    if (fa)
        t[fa].s[w > t[fa].w] = x;
    t[x].init(w, p, fa);
    if (!root)
        root = x;
    while (t[x].fa && p > t[t[x].fa].pr)
        rot(x);
}

int find(int w)
{
    int x = root;
    while (x && t[x].w != w)
        x = t[x].s[w > t[x].w];
    return x;
}

void del(int w)
{
    int x = find(w);
    if (!x)
        return;
    while (t[x].s[0] || t[x].s[1])
    {
        if (!t[x].s[0])
            rot(t[x].s[1]);
        else if (!t[x].s[1])
            rot(t[x].s[0]);
        else
            rot(t[t[x].s[0]].pr > t[t[x].s[1]].pr ? t[x].s[0] : t[x].s[1]);
    }
    if (x == root)
        root = 0;
    else
        t[t[x].fa].s[t[t[x].fa].s[1] == x] = 0;
}

void Pre(int u)
{
    if (u == 0)
        return;
    cout << t[u].w << " ";
    Pre(t[u].s[0]);
    Pre(t[u].s[1]);
}

void In(int u)
{
    if (u == 0)
        return;
    In(t[u].s[0]);
    cout << t[u].w << " ";
    In(t[u].s[1]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    t[0].pr = inf;
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        int x, p;
        cin >> op;
        if (op == "insert")
        {
            cin >> x >> p;
            insert(x, p);
        }
        else if (op == "find")
        {
            cin >> x;
            cout << (find(x) == 0 ? "no\n" : "yes\n");
        }
        else if (op == "delete")
        {
            cin >> x;
            del(x);
        }
        else
        {
            In(root);
            cout << endl;
            Pre(root);
            cout << endl;
        }
    }
    return 0;
}