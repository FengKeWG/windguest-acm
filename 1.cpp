#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
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

int n, idx;
char s[N];
int ch[N][26];
int ne[N], pos[N];
bool vis[M]; // 新增：记录在 A 中出现且满足条件的 Bi

void insert(char *s, int id)
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    pos[p] = id;
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (ch[0][i])
            q.push(ch[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int v = ch[u][i];
            if (v)
                ne[v] = ch[ne[u]][i], q.push(v);
            else
                ch[u][i] = ch[ne[u]][i];
        }
    }
}

void query(const char *str)
{
    for (int i = 0, p = 0; str[i]; ++i)
    {
        p = ch[p][str[i] - 'a'];
        for (int j = p; j; j = ne[j])
        {
            if (pos[j]) // 只处理有效标号
                vis[pos[j]] = true;
        }
    }
}

char p[N], r[N], t[N];
bool can[N];
int Ne[N];

signed main()
{
    // 保持默认同步以免与 scanf 混用出现未定义行为

    int T = read();
    while (T--)
    {
        int n = read();

        // 清空所有全局结构（上一次循环的残留）
        idx = 0;
        memset(ch, 0, sizeof(ch));
        memset(ne, 0, sizeof(ne));
        memset(pos, 0, sizeof(pos));
        memset(vis, 0, sizeof(vis));
        memset(can, 0, sizeof(can));

        // 读取 A 与 C
        scanf("%s%s", p, r); // p = A, r = C

        int m = strlen(r);
        // KMP 失败函数（0 基）
        static int fail[N];
        fail[0] = 0;
        for (int i = 1, j = 0; i < m; ++i)
        {
            while (j && r[i] != r[j])
                j = fail[j - 1];
            if (r[i] == r[j])
                ++j;
            fail[i] = j;
        }

        // 读取 Bi 与 B'i
        for (int id = 1; id <= n; ++id)
        {
            scanf("%s%s", s, t); // s = Bi, t = B'i

            // 判断 B'i 是否包含 C（KMP 匹配）
            int lenT = strlen(t), j = 0;
            bool ok = false;
            for (int k = 0; k < lenT; ++k)
            {
                while (j && t[k] != r[j])
                    j = fail[j - 1];
                if (t[k] == r[j])
                    ++j;
                if (j == m)
                {
                    ok = true;
                    break;
                }
            }
            can[id] = ok;
            if (ok)
                insert(s, id); // 只有满足条件时才插入 AC 自动机
        }

        build();
        query(p); // 在 A 中查询

        // 输出答案
        bool first = true;
        for (int i = 1; i <= n; ++i)
            if (vis[i])
            {
                if (!first)
                    printf(" ");
                printf("%lld", (long long)i);
                first = false;
            }
        printf("\n");
    }
    return 0;
}