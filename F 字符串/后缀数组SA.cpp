#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 2000005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
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

char s[N];
int n, m; // n为后缀个数, m为桶的个数
int x[N], y[N], c[N], sa[N], rk[N], ht[N];
// 桶数组x[i],辅助数组y[i],计数数组c[i]

void get_sa()
{
    int i, j, k;
    // 按第一个字母排序
    for (i = 1; i <= n; i++)
        c[x[i] = s[i]]++;
    for (i = 1; i <= m; i++)
        c[i] += c[i - 1];
    for (i = n; i; i--)
        sa[c[x[i]]--] = i;
    for (k = 1; k <= n; k <<= 1)
    { // logn轮
        // 按第二关键字排序
        memset(c, 0, sizeof(c));
        for (i = 1; i <= n; i++)
            y[i] = sa[i];
        for (i = 1; i <= n; i++)
            c[x[y[i] + k]]++;
        for (i = 1; i <= m; i++)
            c[i] += c[i - 1];
        for (i = n; i; i--)
            sa[c[x[y[i] + k]]--] = y[i];
        // 按第一关键字排序
        memset(c, 0, sizeof(c));
        for (i = 1; i <= n; i++)
            y[i] = sa[i];
        for (i = 1; i <= n; i++)
            c[x[y[i]]]++;
        for (i = 1; i <= m; i++)
            c[i] += c[i - 1];
        for (i = n; i; i--)
            sa[c[x[y[i]]]--] = y[i];
        // 把后缀放入桶数组
        for (i = 1; i <= n; i++)
            y[i] = x[i];
        for (m = 0, i = 1; i <= n; i++)
            if (y[sa[i]] == y[sa[i - 1]] &&
                y[sa[i] + k] == y[sa[i - 1] + k])
                x[sa[i]] = m;
            else
                x[sa[i]] = ++m;
        if (m == n)
            break; // 已排好
    }
}

void get_ht()
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        rk[sa[i]] = i;
    for (i = 1, k = 0; i <= n; i++)
    { // 枚举后缀i
        if (rk[i] == 1)
            continue; // 第一名ht为0
        if (k)
            k--;               // 上一个后缀的ht值减1
        int j = sa[rk[i] - 1]; // 找出后缀i的前邻后缀j
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k])
            k++;
        ht[rk[i]] = k;
    }
}

signed main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    m = 122;
    get_sa();
    get_ht();
    for (int i = 1; i <= n; i++)
        cout << sa[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << ht[i] << ' ';
    // for(int i=1;i<=n;i++)printf("%d ",ht[i]);
    return 0;
}