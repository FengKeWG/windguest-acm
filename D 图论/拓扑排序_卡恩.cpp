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

/*
Kahn(卡恩)算法
e[x]存点x的邻点，
tp 存拓扑序列,
din[x]存点x的入度
算法的核心用队列维护一个入度为0的节点的集合
1.初始化，队列 q压入所有入度为0的点
2.每次从q中取出一个点x放入数组 tp;
3.然后将x的所有出边删除。若将边(x,y)删除后，y的入度
变为0，则将y压入q中
4.不断重复2,3过程，直到队列q为空
5.若tp中的元素个数等于 n，则有拓扑序;否则，有环。
*/

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

int n, m;
vector<int> e[MAXN], tp;
int din[MAXN]; // 入度

bool posort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!din[i])
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        tp.push_back(u);
        for (auto &v : e[u])
        {
            if (--din[v] == 0)
                q.push(v);
        }
    }
    return tp.size() == n;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        din[v]++;
    }
    if (!posort())
        cout << -1 << endl;
    else
        for (auto &x : tp)
            cout << x << " ";
    return 0;
}