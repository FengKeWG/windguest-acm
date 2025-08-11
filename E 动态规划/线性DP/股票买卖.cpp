#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 100005
#define MOD 1000000007
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
    int n = read();
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = read();
    vector<vector<int>> f(n + 1, vector<int>(2));
    // f[i][1] 手中有票
    f[1][1] = -a[1];
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);
    }
    // 如果 i 从 1 开始
    /*
    f[0][1] = -INF;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + a[i]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);
    }
    */
    cout << max(f[n][0], f[n][1]);
    return 0;
}

/*
【题目】
给定一个长度为N的数组，数组中的
第i个数字表示一个给定股票在第i天
的价格。
设计一个算法来计算你所能获取的最大
利润。你可以尽可能地完成更多的交易
(多次买卖一支股票)
注意:你不能同时参与多笔交易(你必
须在再次购买前出售掉之前的股票)
一次买入卖出合为一笔交易。
【输入格式】
第一行包含整数N，表示天数。
第二行包含N个不大于 10000的正整数
表示每天股票的价格。
【输出格式】
输出一个整数，表示最大利润
*/