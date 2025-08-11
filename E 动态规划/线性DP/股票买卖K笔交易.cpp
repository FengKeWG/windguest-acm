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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), k = read();
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = read();
    // int f[n + 1][k + 1][2];
    // memset(f, 0, sizeof f);
    // for (int j = 0; j <= k; j++)
    //     f[0][j][1] = -INF;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + a[i]);
    //         f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - a[i]);
    //     }
    // }
    // cout << f[n][k][0];

    int f[k + 1][2];
    memset(f, 0, sizeof f);
    for (int j = 0; j <= k; j++)
        f[j][1] = -INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            f[j][0] = max(f[j][0], f[j][1] + a[i]);
            f[j][1] = max(f[j][1], f[j - 1][0] - a[i]);
        }
    }
    cout << f[k][0];
    return 0;
}

/*
【题日】
给定一个长度为N的数组，数组中的
第i个数字表示一个给定股票在第i天
的价格。
设计一个算法来计算你所能获取的最大
利润，你最多可以完成K笔交易。
注意:你不能同时参与多笔交易(你必
须在再次购买前出售掉之前的股票)
一次买入卖出称为一笔交易。
【输入格式】
第一行包含两个整数N,K，分别表示天
数和交易笔数。
第二行包含N个不大于 10000的正整数:
表示每天股票的价格。
【输出格式】
输出一个整数，表示最大利润。
*/