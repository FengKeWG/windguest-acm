#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

/*
ne[v]存节点v的回跳边的终点。
回跳边指向父节点的回跳边所指节点的儿子
四个点(v,u,ne[u],ch[][])构成四边形
回跳边所指节点一定是当前节点的最长后缀

原点儿子的回跳边就是原点

ch[u][i]存节点u的树边的终点。
ch[u][i]存节点u的转移边的终点。
转移边指向当前节点的回跳边所指节点的儿子。
三个点(u,ne[u],ch[][])构成三角形。
转移边所指节点一定是当前节点的最短路
*/

/*
查找单词出现次数
扫描主串，依次取出字符 s[k]
1.i指针走主串对应的节点，沿着树边或转移边走
保证不回退。
i指针沿着回跳边搜索模式串，每次从当前节点
走到根节点，把当前节点中的所有后缀模式串
一网打尽，保证不漏解。
扫描完主串，返回答案
算法一边走串，一边把当前串的所有后缀串搜
出来，实在是强。
*/

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
int ne[N], cnt[N];

void insert(char *s) // Tire 数
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = s[i] - 'a';
        if (!ch[p][j])
            ch[p][j] = ++idx;
        p = ch[p][j];
    }
    cnt[p]++;
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
                ne[v] = ch[ne[u]][i], q.push(v); // 回跳边
            else
                ch[u][i] = ch[ne[u]][i]; // 转移边
        }
    }
}

int query(char *s)
{
    int ans = 0;
    for (int k = 0, i = 0; s[k]; k++)
    {
        i = ch[i][s[k] - 'a'];
        for (int j = i; j && ~cnt[j]; j = ne[j])
            ans += cnt[j], cnt[j] = -1;
    }
    return ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s, insert(s);
    build();
    cin >> s;
    cout << query(s) << endl;
    return 0;
}