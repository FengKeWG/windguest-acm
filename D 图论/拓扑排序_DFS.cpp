#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 100005
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

/*
e[x]存点x的邻点，tp 存拓扑序列，c[x]存点x的颜色。
算法的核心是变色法，一路搜一路给点变色，如果有拓扑序，每
经历三次变色。
个点的颜色都会从0→-1→1,
1.初始状态，所有点染色为0。
2.枚举每个点，进入x点，把x染色为-1。然后，枚举x的儿
子y，如果y的颜色为0，说明没碰过该点，进入y继续走
3.如果枚举完x的儿子，没发现环，则x染色为1，并把x压入
tp 数组。
4.如果发现有个熊孩子的颜色为-1，说明回到了祖先节点，发
现了环，则一路返回 false，退出程序。
*/

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}