#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 3000005
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

int ch[MAXN][65]; // 从节点p通过j这个字母转移到的节点编号
int cnt[MAXN];    // 以节点p结尾的单词插入次数
char s[MAXN];
int idx;

int getnum(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    else
        return c - '0' + 52;
}

void insert(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = getnum(s[i]);
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
    }
    // 如果只统计整个字符串数目，cnt[p]++ 放在这里
}

int query(char *s)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = getnum(s[i]);
        if (!ch[p][j])
            return 0;
        p = ch[p][j];
    }
    return cnt[p];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i <= idx; i++)
            for (int j = 0; j < 130; j++)
                ch[i][j] = 0;
        for (int i = 0; i <= idx; i++)
            cnt[i] = 0;
        idx = 0;
        int n, q;
        cin >> n >> q;
        while (n--)
        {
            cin >> s;
            insert(s);
        }
        while (q--)
        {
            cin >> s;
            cout << query(s) << endl;
        }
    }
    return 0;
}