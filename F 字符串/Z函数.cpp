// 对于一个长度为n的字符串S。z[] 表示S与其后缀S[i,n]的最长公共前缀(LCP)的长度。

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

char s[MAXN];
int z[MAXN];

void getz(char *s, int n)
{
    z[1] = n;
    int l, r = -1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        while (s[1 + z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> (s + 1);
    int n = strlen(s + 1);
    getz(s, n);
    for (int i = 1; i <= n; i++)
        cout << z[i] << " ";
    return 0;
}

/*
算法流程
计算完 前i-1个z函数，维护盒子[,r]，则 sl,r]= s[1,r-l+ 1]
1. 如果i≤r(在盒内)，则有 s[i,r= s[i-l+ 1,r-l+ 1]。
(1)若z[i-l+1]<r-i+1，则 z{i]= z[i-ㄧ+ 1]。
从r+1往后暴力枚举
(2)若zi-1+1>r-i+1
则令zi=r-i+1,
2.如果i>r(在盒外)，则从i开始暴力枚举。
3.求出z[i后，如果i+zi-1>r，则更新盒子l=ir=i+z[i]-1.
*/