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

int n, m;
int cnt = 0;
int g[105];
int s[1 << 10];
int num[1 << 10];
int f[105][1 << 10][1 << 10];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == 'P')
                g[i] += 1 << (m - j);
        }
    }
    for (int i = 0; i < (1 << m); i++)
    {
        if (!(i & i << 1) && !(i & i << 2)) // 一格和两格都不能有跑炮兵
        {
            s[cnt++] = i;
            for (int j = 0; j < m; j++)
                num[i] += (i >> j & 1);
        }
    }
    for (int i = 1; i <= n + 2; i++)
        for (int a = 0; a < cnt; a++)
            for (int b = 0; b < cnt; b++)
                for (int c = 0; c < cnt; c++)
                    if (!(s[a] & s[b]) && !(s[a] & s[c]) && !(s[b] & s[c]) && (g[i] & s[a]) == s[a] && (g[i - 1] & s[b]) == s[b])
                        f[i][a][b] = max(f[i][a][b], f[i - 1][b][c] + num[s[a]]);

    cout << f[n + 2][0][0];
    return 0;
}

/*
【题目】
司令部的将军们打算在N*M的网格地图上部署他们
的炮兵部队。地图由N行M列组成，地图的每一格可能
是山地(用H表示)，也可能是平原(P表示)
在每一格平原上最多可以布置一支炮兵部队，山地
上不能部署炮兵部队;
一支炮兵部队在地图上的攻击范
围如图中黑色区域所示:沿横向左右各两格，沿纵向上
下各两格。图上其它白色网格均攻击不到。炮兵的攻击
范围不受地形的影响。
现在，将军们如何部署炮兵部队，在防止误伤的前
提下(保证任何两支炮兵部队之间不能互相攻击，即任
何一支炮兵部队都不在其他支炮兵部队的攻击范围内)
在整个地图区域内最多能摆放多少炮兵部队。
【输入格式】
第一行包含两个正整
数，分别表示N和M;
NS100, MS10.
接下来的N行，每
行含有连续的M个字符
(P或H)，中间没有空格。
按顺序表示地图中每一
行的数据。
【输出格式】
仅一行，包含一个整
数，表示最多能摆放的
炮兵部队的数量。
【输入样例】
3 4
PHHP
HPHP
HHPH
【输出样例】
*/