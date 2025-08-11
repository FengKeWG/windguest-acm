#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

// 不能拿相邻的，求最多可以拿多少？

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
    int T = read();
    while (T--)
    {
        int n = read();
        int a[n + 1];
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }
        // 法 1
        vector<int> f(n + 1);
        f[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            f[i] = max(f[i - 1], f[i - 2] + a[i]); // 不偷第 i 家, 偷第 i 家
        }
        cout << f[n] << endl;
        // 法 2
        /*
        vector<vector<int>> f(n + 1, vector<int>(2));
        f[1][1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            f[i][1] = f[i - 1][0] + a[i];
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
        }
        cout << max(f[n][1], f[n][0]) << endl;
        */
    }
    return 0;
}

/*
阿福是一名经验丰富的大盗。趁着月黑风高，阿福打算
今晚洗劫一条街上的店铺。这条街上一共有N家店铺，
每家店中都有一些现金。阿福事先调查得知，只有当他
同时洗劫了两家相邻的店铺时，街上的报警系统才会启
动，然后警察就会蜂拥而至。作为一向谨慎作案的大盗
阿福不愿意冒着被警察追捕的风险行窃。他想知道，在
不惊动警察的情况下，他今晚最多可以得到多少现金?
【输入格式】
输入的第一行是一个整数T，表示一共有T组数据
接下来的每组数据，第一行是一个整数N，表示
有N家店铺。
第二行是N个被空格分开的正整数，表示每一家店铺中
的现金数量。每家店铺中的现金数量均不超过1000。
【输出格式】
对于每组数据，输出一行。该行包含一个整数，表示阿
福在不惊动警察的情况下可以得到的现金数量。
*/