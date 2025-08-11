/*
数位DP的特点:求某个区间[L,R内，满足某种性质的数的个数。
数位DP的技巧1:类似前缀和思想，转化为[0,R]-[0,L-1]求解。
数位DP的技巧2:从高位到低位填数，要分类讨论
把整数R的每一位抠出来，存入数组a，则 R=anan-1 an2… a1
从高位到低位填数，划分两类:0~a;-1和a;
如果i位填o~a;-1，则后面每一位可以填0~9，
如果i位填a;，则再讨论下一位。这样，保证填的数不超过R。
*/

// 题目：查找不降数

#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 12
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

int l, r;
int a[N];
int f[N][N]; // f[i][j]，一共有 i 位，最高位是 j 的不降数个数

void pre()
{
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = j; k <= 9; k++)
                f[i][j] += f[i - 1][k];
}

int cal(int n)
{
    if (n == 0) // 注意特判
        return 1;
    int cnt = 0;
    while (n)
    {
        a[++cnt] = n % 10;
        n /= 10;
    }
    int res = 0;
    int last = 0;
    for (int i = cnt; i > 0; i--)
    {
        int now = a[i];
        for (int j = last; j < now; j++) // 当 j = now 的时候，就不在这一位讨论了，到下一位，i--
        {
            res += f[i][j];
        }
        if (now < last)
            break;
        last = now;
        if (i == 1)
            res++;
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    while (cin >> l >> r)
        cout << cal(r) - cal(l - 1) << endl;
    return 0;
}

/*
数位DP的特点: 求某个区间[L,R]内，满足某种性质的数的个数，
数位DP的技巧1: 类似前缀和思想，转化为 [0,R] - [0,L-1] 求解。
数位DP的技巧2: 从高位到低位填数，要分类讨论
把整数R的每一位抠出来，存入数组a，则R=an an-1 an-2…. a1，
从高位到低位填数，划分两类:0~a;-1和a;
如果i位填0~ai-1 -> 则后面每一位可以填0~9
如果i位填ai -> 则再讨论下一位。这样，保证填的数不超过R。
*/