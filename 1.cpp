#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 2e6 + 10;
char str[N];
vector<int> e[N]; // 邻接表
LL cnt[N], ans;
int tot = 1, np = 1;
// fa链接边终点,ch转移边终点,len最长串长度
int fa[N], ch[N][26], len[N];

void extend(int c)
{
    // p回跳指针, np新点, q链接点, nq新链接点
    int p = np;
    np = ++tot; // p指向旧点, np是新点
    len[np] = len[p] + 1;
    cnt[np] = 1; // 子串出现次数
    // p沿链接边回跳，从旧点向新点建转移边
    for (; p && !ch[p][c]; p = fa[p])
        ch[p][c] = np;

    // 1.如果c是新字符，从新点向根节点建链接边
    if (p == 0)
        fa[np] = 1;
    else
    {                     // 如果c是旧字符
        int q = ch[p][c]; // q是链接点
        // 2.若链接点合法，从新点向q建链接边
        if (len[q] == len[p] + 1)
            fa[np] = q;
        // 3.若链接点不合法，则裂开q点，重建两类边
        else
        {
            int nq = ++tot; // nq是新链接点
            len[nq] = len[p] + 1;
            // 重建nq,q,np的链接边
            fa[nq] = fa[q];
            fa[q] = nq;
            fa[np] = nq;
            // 指向q的转移边改为指向nq
            for (; p && ch[p][c] == q; p = fa[p])
                ch[p][c] = nq;
            // 从q发出的转移边复制给nq
            memcpy(ch[nq], ch[q], sizeof(ch[q]));
        }
    }
}
void dfs(int u)
{
    for (auto v : e[u])
    {
        dfs(v);
        cnt[u] += cnt[v];
    }
    if (cnt[u] > 1)
        ans = max(ans, cnt[u] * len[u]);
}
int main()
{
    scanf("%s", str);
    for (int i = 0; str[i]; i++)
        extend(str[i] - 'a');
    for (int i = 2; i <= tot; i++)
        e[fa[i]].push_back(i);
    cout << len[7] << endl;
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}