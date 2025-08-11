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
用 Trie 存单词
由26个小写字母构造的 Trie ，是一颗26叉树，深度为最长单词的长度
用 Trie 存整数
由整数的十进制位构造的 Trie ，是一颗10叉树，深度为 10 层。
用 Trie 存整数
由整数的二进制位构造的 Trie，是一颗二叉树，深度为 31层
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

int ch[MAXN * 31][2];
int idx;
int n, a[MAXN];

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--) // 要从最大的30开始枚举，因为之后要比较不同位，可能很大的数字和很小的数比较，所以就算是很小的数字也要从30开始枚举。
    {
        int j = x >> i & 1;
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
}

int query(int x)
{
    int res = 0;
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = x >> i & 1;
        if (ch[p][!j]) // 求抑或，只有位数字不同，才=1，所以要找不同的
        {
            res += 1 << i;
            p = ch[p][!j];
        }
        else
            p = ch[p][j];
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        insert(a[i]);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
    return 0;
}

/*
题目
给定N个整数 a1，a2… aN,
任选两个进行异或运算，得到的结果最大是多少?
*/