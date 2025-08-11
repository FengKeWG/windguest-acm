#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
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

/*
新建一个虚拟源点 0，从该点向其他所有点连一条边权为0的边，再用
spfa 算法求出从0号点到其他所有点的最短路 h(i)。
将新图的边权改造为 w(u,v)+ h(u)- h(v)
这样能确保边权非负，
以每个点为起点，跑n轮 Heap-Diikstra 算法，求出任意两点间最短路
*/

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}