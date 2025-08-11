#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 35
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

int l, r, k, b;
int a[MAXN];
int f[MAXN][MAXN]; // 在 i 个位置上，放置 j 个 1

void pre()
{
    for (int i = 0; i <= MAXN; i++)
        f[i][0] = 1;
    for (int i = 1; i <= MAXN; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    // Ci,j = Ci-1,j + Ci-1,j-1;
}

int calc(int n)
{
    if (!n)
        return 0;
    int res = 0, cnt = 0;
    while (n)
    {
        a[++cnt] = n % b; // b进制
        n /= b;
    }
    int last = 0; // 第 i 位之前放置 1 的个数
    for (int i = cnt; i > 0; i--)
    {
        int now = a[i];
        if (now)
        {
            res += f[i - 1][k - last];
            if (now > 1)
            {
                if (k - last - 1 >= 0)
                    res += f[i - 1][k - last - 1];
                break;
            }
            else
            {
                last++;
                if (last > k)
                    break;
            }
        }
        if (i == 1 && last == k)
            res++;
    }
    return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    while (cin >> l >> r >> k >> b)
    {
        cout << calc(r) - calc(l - 1) << endl;
    }
    return 0;
}

/*
【题目】
求给定区间[X,Y]中满足下列条件的整数个数:
这个数恰好等于K个互不相等的B的整数次幂之和
例如，设X=15,Y=20,K=2,B=2，则有且仅有下列二
个数满足题意:
17=2^4+2^0
18 =2^4+2^1
20=2^4+2^2
【输入格式】
第一行包含两个整数X和Y，接下来两行包含整数
K和B。
【输出格式】
只包含一个整数，表示满足条件的数的个数。
【输入样例】
15 20
N
2
【输出样例】
*/