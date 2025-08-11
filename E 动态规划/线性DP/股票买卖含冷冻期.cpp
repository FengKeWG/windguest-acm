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
    int n = read();
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = read();
    vector<vector<int>> f(n + 1, vector<int>(3));
    f[0][1] = -INF;
    f[0][0] = -INF;
    // f[i][1] 有票，f[i][0]无票，卖完后第一天，f[i][2]无票，卖完后>=2天
    // 使用第二维共三个状态，可以避免从多天前的转移
    for (int i = 1; i <= n; i++)
    {
        f[i][1] = max(f[i - 1][1], f[i - 1][2] - a[i]);
        f[i][0] = f[i - 1][1] + a[i];
        f[i][2] = max(f[i - 1][0], f[i - 1][2]);
    }
    cout << max({f[n][0], f[n][1], f[n][2]});
    return 0;
}

/*
【题日】
给定一个长度为N的数组，数组中的
第i个数字表示一个给定股票在第i天
的价格。
设计一个算法计算出最大利润。在满足
以下约束条件下，你可以尽可能地完成
更多的交易(多次买卖一支股票):
。你不能同时参与多笔交易(你必须在
再次购买前出售掉之前的股票)。
·卖出股票后，你无法在第二天买入股
票(即冷冻期为 1天)
【输入格式】
第一行包含整数N，表示天数。
第二行包含N个不大于 10000的正整数
表示每天股票的价格。
【输出格式】
输出一个整数，表示最大利润
*/