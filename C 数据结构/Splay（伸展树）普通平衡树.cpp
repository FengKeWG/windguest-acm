#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
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
    int s[2]; // 左右儿子
    int fa;   // 父亲
    int w;
    int cnt;  // 权值 w 出现的次数
    int size; // 子树大小
    void init(int fa1, int w1)
    {
        fa = fa1, w = w1;
        cnt = size = 1;
    }
} t[N];
// 二叉搜索树，中序遍历递增

int root, idx;

void up(int x)
{
    t[x].size = t[t[x].s[0]].size + t[t[x].s[1]].size + t[x].cnt;
}

void rot(int x)
{
    int y = t[x].fa, z = t[y].fa;
    int k = t[y].s[1] == x;    // 以左旋举例
    t[y].s[k] = t[x].s[k ^ 1]; // x是y的右儿子 -> k=1 -> y的右儿子=x的左儿子
    t[t[x].s[k ^ 1]].fa = y;   // x左儿子的父亲变为y
    t[x].s[k ^ 1] = y;         // x的左儿子变成y
    t[y].fa = x;
    t[z].s[t[z].s[1] == y] = x; // z原来是y的父亲，x转过去之后，z就变成了x的父亲
    t[x].fa = z;
    up(y), up(x);
}

void splay(int x, int k) // 把x上升到k底下
{
    while (t[x].fa != k)
    {
        int y = t[x].fa, z = t[y].fa;
        // 双旋的第一次
        if (z != k)
            (t[y].s[0] == x) ^ (t[z].s[0] == y) ? rot(x) : rot(y); // 直线形转y，折线形转x
        // 第二次或者单旋
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
    if (x) // 已经有了++cnt
        t[x].cnt++;
    else // 没找到w
    {
        x = ++idx;
        t[fa].s[w > t[fa].w] = x;
        t[x].init(fa, w);
    }
    splay(x, 0);
}

void find(int w)
{
    int x = root;
    while (t[x].s[w > t[x].w] && w != t[x].w)
        x = t[x].s[w > t[x].w];
    splay(x, 0);
    // 如果没有这个数字，就会一直找到最底下，然后上升转到根
}

int get_pre(int w) // 求w的前驱
{
    find(w); // 找到它，转到根
    int x = root;
    if (t[x].w < w) // 不存在w
        return x;
    x = t[x].s[0];    // 先去左子树
    while (t[x].s[1]) // 然后不断变大，逼近 w，得到小于w的最大值
        x = t[x].s[1];
    return x;
}

int get_suc(int w)
{
    find(w);
    int x = root;
    if (t[x].w > w)
        return x;
    x = t[x].s[1];
    while (t[x].s[0])
        x = t[x].s[0];
    return x;
}

void del(int w)
{
    int pre = get_pre(w);
    int suc = get_suc(w);
    splay(pre, 0);         // 前驱转到根上
    splay(suc, pre);       // 后继转到前驱下面
    int del = t[suc].s[0]; // 要删除的就是后继节点的左儿子
    if (t[del].cnt > 1)
        t[del].cnt--, splay(del, 0); // splay目的是更新受影响的点
    else
        t[suc].s[0] = 0, splay(suc, 0);
}

int get_rank(int w)
{
    insert(w);
    int res = t[t[root].s[0]].size;
    del(w);
    return res;
}

int get_val(int k) // 排名为k的权值
{
    int x = root;
    while (1)
    {
        int l = t[x].s[0];
        if (t[l].size + t[x].cnt < k) // 说明k比较大，要去右子树找
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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    insert(-inf), insert(inf);
    int q = read();
    while (q--)
    {
        int op = read(), x = read();
        if (op == 1)
            insert(x);
        if (op == 2)
            del(x);
        if (op == 3)
            cout << get_rank(x) << endl;
        if (op == 4)
            cout << get_val(x + 1) << endl; // 获取排名要+1，因为存在-inf的哨兵
        if (op == 5)
            cout << t[get_pre(x)].w << endl;
        if (op == 6)
            cout << t[get_suc(x)].w << endl;
    }
    return 0;
}