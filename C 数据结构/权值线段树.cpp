#include <bits/stdc++.h>
#define int long long // 使用 long long 类型，防止数据溢出
// #define int unsigned long long
// #define int __int128
#define endl '\n'          // 使用 '\n' 代替 endl，提高效率
#define N 100005           // 定义数组大小
#define MOD 1000000007     // 定义模数，用于取模运算
#define eps 1e-6           // 定义精度
#define inf 0x3f3f3f3f     // 定义无穷大
#define pii pair<int, int> // 定义 pair 类型
#define mid ((x + y) >> 1) // 定义 mid 宏，用于二分
#define ls (r << 1)        // 定义 ls 宏，表示左子节点
#define rs (r << 1 | 1)    // 定义 rs 宏，表示右子节点
using namespace std;
// 快速输出函数
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
// 快速读取函数
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
求逆序对
*/
int n, a[N], b[N]; // 定义 n：数组大小，a[N]：原数组，b[N]：排序后的数组
int s[N << 2];     // 定义线段树数组，大小为 4N
// 更新节点信息
void up(int r)
{
    s[r] = s[ls] + s[rs]; // 节点信息等于左右子节点之和
}
// 单点修改，将 k 位置的值加 1
void change(int r, int x, int y, int k)
{
    if (x == y)
    {
        s[r]++; // 叶子节点的值加 1
        return;
    }
    if (k <= mid)
        change(ls, x, mid, k); // 如果 k 在左子树，则修改左子树
    else
        change(rs, mid + 1, y, k); // 如果 k 在右子树，则修改右子树
    up(r);                         // 更新节点信息
}
// 区间查询，查询 [xx, yy] 区间的和
int query(int r, int x, int y, int xx, int yy)
{
    if (xx <= x && y <= yy)
        return s[r]; // 如果当前区间被包含在查询区间内，则直接返回节点值
    int S = 0;       // 定义 S 存储结果
    if (xx <= mid)
        S += query(ls, x, mid, xx, yy); // 如果查询区间与左子树有交集，则查询左子树
    if (yy > mid)
        S += query(rs, mid + 1, y, xx, yy); // 如果查询区间与右子树有交集，则查询右子树
    return S;                               // 返回结果
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0); // 关闭同步，提高效率
    n = read();                     // 读取数组大小
    for (int i = 1; i <= n; i++)
        a[i] = read(), b[i] = a[i]; // 读取原数组，并复制到 b 数组
    sort(b + 1, b + 1 + n);         // 对 b 数组进行排序
    int S = 0;                      // 定义 S 存储逆序对个数
    for (int i = 1; i <= n; i++)
    {
        int id = lower_bound(b + 1, b + 1 + n, a[i]) - b; // 找到 a[i] 在 b 数组中的排名
        change(1, 1, n, id);                              // 将 id 位置的值加 1
        S += query(1, 1, n, id + 1, n);                   // 查询 [id+1, n] 区间的和，即为逆序对个数
    }
    cout << S << endl; // 输出逆序对个数
    return 0;
}