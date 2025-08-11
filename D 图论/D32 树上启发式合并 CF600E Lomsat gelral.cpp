#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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
先跑重链剖分，预处理出每个节点的重儿子。
用cnt[] 记录颜色i的出现次数，ans[x]记录结点×的答案。我们遍历一个节点×，按以下步骤进行：
1.先遍历×的轻儿子，并计算答案，但不保留遍历后它对
cnt数组的贡献;
2.遍历×的重儿子，保留遍历后它对 cnt数组的贡献;3．再次遍历×的轻儿子，加入轻子树的贡献，得到×的答
案。（树上启发式合并：轻子树的结果并入重子树）为什么不合并第一步和第三步呢？
因为我们要重复使用cnt数组，a子树不能影响b子树。对于一个节点，我们遍历了一次重子树，两次轻子树。
*/

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}

/*
有一棵n 个结点的以 1 号结点为根的有根树。
每个结点都有一个颜色，颜色是以编号表示的，号结点的颜色编号为ci。
如果一种颜色在以为根的子树内出现次数最多，称其在以为根的子树中占主导地位。显然，同一子树中可能有多种颜色占主导地位。
你的任务是求出以为根的子树中，占主导地位的颜色的编号和。
*/