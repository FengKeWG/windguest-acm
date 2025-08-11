/*
并查集是一种树形的数据结构
支持两种操作:
合并:将两个子集合并成一个集合。
查找:确定某个元素处在哪个集合。

查找
根节点是集合的代表
查找就是找到元素所在
集合的根
1.如果父节点等于自己
则找到了根并返回。
2.如果还没找到根，则
继续递归查找。

带路径压缩的查找
在返回的路上，顺带修改
各节点的父节点为根

按秩合并(启发式合并)
把小集合的根指向大集合的根，
*/

#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1000005
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

int fa[MAXN];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void uni(int x, int y)
{
    fa[find(x)] = find(y);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int op = read(), x = read(), y = read();
        if (op == 1)
            uni(x, y);
        else if (find(x) == find(y))
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}