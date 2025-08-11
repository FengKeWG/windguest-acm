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

int f[2][1 << 14];
int s[1 << 14];
int cnt = 0;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read(), m = read();
    int e[n + 1];
    for (int i = 1; i <= n; i++)
    {
        e[i] = 0;
        for (int j = 1; j <= m; j++)
        {
            int tmp = read();
            e[i] += tmp * (1 << (m - j));
        }
    }

    for (int i = 0; i < (1 << m); i++)
        if (!(i & i << 1))
            s[cnt++] = i;
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        int now = i & 1, pre = i - 1 & 1;
        memset(f[now], 0, sizeof(f[now]));
        for (int a = 0; a < cnt; a++)
        {
            for (int b = 0; b < cnt; b++)
            {
                if (!(s[a] & s[b]) && (s[a] & e[i]) == s[a])
                {
                    f[now][a] += f[pre][b];
                }
            }
        }
    }
    cout << f[n + 1 & 1][0];
    return 0;
}

/*
【题日】
农夫约翰的土地由n*m个小方格组成，现在他要在土
地里种植玉米。相邻的土地不能同时种植玉米，也就
是说种植玉米的所有方格之间都不会有公共边缘。而
且，部分土地是不育的，无法种植，
现在给定土地的大小，请你求出共有多少种种植方案
土地上什么都不种也算一种方案。
【输入格式】
第1行包含两个整数n和m。1sn,m≤12.
第2..n+1行:每行包含m个整数0或1，1表示该块土地
肥沃，0表示该块土地不育。
输出格式】
输出总种植方案对100000000取模后的值。
【输入样例】
2 3
110
0 1 1
【输出样例】
*/