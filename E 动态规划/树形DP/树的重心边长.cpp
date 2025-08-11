#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
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

int n, ans = inf;
vector<int> e[N];

int dfs(int u, int fa)
{
    int sum = 1;  // 以u为根的数总共有多少节点
    int size = 0; // 以u为根的所有子数中，节点最多的有多少
    for (auto &v : e[u])
    {
        if (v != fa)
        {
            int s = dfs(v, u);
            sum += s;
            size = max(size, s);
        }
    }
    ans = min(ans, max(n - sum, size)); // n-sum：u上面共有多少节点
    return sum;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}

/*

【题目】
给定一颗树，树中包含n个结点(编号1~n)和n-1
条无向边。
请你找到树的重心，并输出将重心删除后，剩余
各个连通块中点数的最大值。
重心定义:重心是指树中的一个结点，如果将这
个点删除后，剩余各个连通块中点数的最大值最小
那么这个结点被称为树的重心。
【输入格式】
第一行包含整数n，表示树的结点数。1sns105
接下来n-1行，每行包含两个整数a和b，表示点a和
点b之间存在一条边。
【输出格式】
输出一个整数m，表示将重心删除后，剩余各个连
通块中点数的最大值。
*/