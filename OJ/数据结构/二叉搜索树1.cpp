#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 500005
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
    int fa;
    int w;
    int cnt;
    int size;
    void init(int fa1, int w1)
    {
        fa = fa1, w = w1;
        cnt = size = 1;
    }
} t[N];

int root, idx;

void up(int x)
{
    t[x].size = t[t[x].s[0]].size + t[t[x].s[1]].size + t[x].cnt;
}

void rot(int x)
{
    int y = t[x].fa, z = t[y].fa;
    int k = t[y].s[1] == x;
    t[y].s[k] = t[x].s[k ^ 1];
    t[t[x].s[k ^ 1]].fa = y;
    t[x].s[k ^ 1] = y;
    t[y].fa = x;
    t[z].s[t[z].s[1] == y] = x;
    t[x].fa = z;
    up(y), up(x);
}

void splay(int x, int k)
{
    while (t[x].fa != k)
    {
        int y = t[x].fa, z = t[y].fa;
        if (z != k)
            (t[y].s[0] == x) ^ (t[z].s[0] == y) ? rot(x) : rot(y);
        rot(x);
    }
    if (k == 0)
        root = x;
}

void insert(int w)
{
    int x = root, fa = 0;
    while (x && t[x].w != w)
    {
        fa = x;
        x = t[x].s[w > t[x].w];
    }
    if (x)
        t[x].cnt++;
    else
    {
        x = ++idx;
        t[fa].s[w > t[fa].w] = x;
        t[x].init(fa, w);
        if (!root)
            root = x;
    }
    // splay(x, 0);
}

// void find(int w)
// {
//     int x = root;
//     while (t[x].s[w > t[x].w] && w != t[x].w)
//         x = t[x].s[w > t[x].w];
//     splay(x, 0);
// }

int find(int w)
{
    int x = root;
    while (t[x].s[w > t[x].w] && w != t[x].w)
        x = t[x].s[w > t[x].w];
    if (t[x].w == w)
        return x;
    else
        return 0;
}

// int get_pre(int w)
// {
//     find(w);
//     int x = root;
//     if (t[x].w < w)
//         return x;
//     x = t[x].s[0];
//     while (t[x].s[1])
//         x = t[x].s[1];
//     return x;
// }

// int get_suc(int w)
// {
//     find(w);
//     int x = root;
//     if (t[x].w > w)
//         return x;
//     x = t[x].s[1];
//     while (t[x].s[0])
//         x = t[x].s[0];
//     return x;
// }

void del(int w)
{
    int x = find(w);
    if (!x)
        return;
    if (!t[x].s[0] && !t[x].s[1])
    {
        if (t[x].fa)
            t[t[x].fa].s[0] == x ? t[t[x].fa].s[0] = 0 : t[t[x].fa].s[1] = 0;
        else
            root = 0;
    }
    else if (t[x].s[0] && t[x].s[1])
    {
        int r = t[x].s[1];
        while (t[r].s[0])
            r = t[r].s[0];
        t[x].w = t[r].w;
        int f = t[r].fa;
        t[f].s[0] == r ? t[f].s[0] = t[r].s[1] : t[f].s[1] = t[r].s[1];
        if (t[r].s[1])
            t[t[r].s[1]].fa = f;
    }
    else
    {
        int ch = t[x].s[0] ? t[x].s[0] : t[x].s[1];
        if (t[x].fa)
        {
            int f = t[x].fa;
            t[f].s[0] == x ? t[f].s[0] = ch : t[f].s[1] = ch;
            t[ch].fa = f;
        }
        else
        {
            root = ch;
            t[ch].fa = 0;
        }
    }
}

int get_rank(int w)
{
    insert(w);
    int res = t[t[root].s[0]].size;
    del(w);
    return res;
}

int get_val(int k)
{
    int x = root;
    while (1)
    {
        int l = t[x].s[0];
        if (t[l].size + t[x].cnt < k)
        {
            k -= t[l].size + t[x].cnt;
            x = t[x].s[1];
        }
        else
        {
            if (t[l].size >= k)
                x = t[x].s[0];
            else
                break;
        }
    }
    splay(x, 0);
    return t[x].w;
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
    // insert(-inf), insert(inf);
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        int x;
        cin >> op;
        if (op == "insert")
        {
            cin >> x;
            insert(x);
        }
        else if (op == "find")
        {
            cin >> x;
            if (find(x))
                cout << "yes\n";
            else
                cout << "no\n";
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