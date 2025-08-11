/*
状态压缩存储：
用二进制表示状态，
用十进制数存储状态。
*/

/*
1.行内合法:如果!(i& i>>1)为真，则i合法（没有相邻的1）
i=5: 1 0 1 -> 0
     0 1 0
i=6: 1 1 0 -> 1
     0 1 1

2.行间兼容:如果!(a&b) && !(a&b>>1) && !(a&b<<1)为真，则 a,b 兼容
        保证同一列不为1   排除左对角不能放1   排除右对角不能放1
b: [0 0 0],[0 0 1],[0 1 0],[1 0 0],[1 0 1]
a: [0 0 0],[0 0 1],[0 1 0],[1 0 0],[1 0 1]
例如a的第二个和b的第一个、第四个兼容

3.状态表示:f[i,j,a]表示前i行已放了j个国王，第i行的第a个状态的方案数
*/

#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 100005
#define MOD 1000000007
#define eps 1e-6
#define INF LLONG_MAX
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

int n, k;
int cnt = 0;
int s[1 << 12];          // 每一行合法的状态
int num[1 << 12];        // 合法的状态的国王个数
int f[12][144][1 << 12]; // f[i,j,a]表示前i行放了j个国王，第i行是第a个状态时的方案数

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 0; i < (1 << n); i++)
    {
        if (!(i & i >> 1))
        {
            s[cnt++] = i;
            for (int j = 0; j < n; j++)
                num[i] += i >> j & 1;
        }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= k; j++)
            for (int a = 0; a < cnt; a++)
                for (int b = 0; b < cnt; b++)
                {
                    int c = num[s[a]];
                    if (j >= c && !(s[a] & s[b]) && !(s[a] & s[b] << 1) && !(s[a] & s[b] >> 1))
                        f[i][j][a] += f[i - 1][j - c][b];
                }
    cout << f[n + 1][k][0];
    return 0;
}

/*
【题日】
在nxn的棋盘上放k个国王，国王可
攻击相邻的8个格子，求使他们无法互相
攻击的方案总数。
【输入格式】
共一行，包含两个整数n和k。
1≤ns10,oskSn2
【输出格式】
共一行，表示方案总数，若不能够放置
则输出0。
【输入样例】
3 2
【输出样例】
16
*/