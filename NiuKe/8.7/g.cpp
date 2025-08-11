#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 100005
#define M 1000000007
#define mid (l + r >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
// #define int long long

using namespace std;

inline int read()
{
    int res = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f *= -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        res = res * 10 + c - '0';
        c = getchar();
    }
    return res * f;
}

map<int, int> mp[N];
int r[N], siz[N], fa[N], cnt[N];

struct edge
{
    int x, y, w;
} e[N << 1];

bool cmp(edge u, edge v)
{
    return u.w < v.w;
}

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

signed main()
{
    int t = read();
    while (t--)
    {
        int n = read(), m = read(), k = read();
        for (int i = 1; i <= n; i++)
            mp[i].clear(), fa[i] = i, siz[i] = 1, cnt[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            e[i].x = read();
            e[i].y = read();
            e[i].w = read();
            mp[e[i].x][e[i].y]++;
            mp[e[i].y][e[i].x]++;
            cnt[e[i].x]++;
            cnt[e[i].y]++;
        }
        sort(e + 1, e + m + 1, cmp);
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int fx = find(e[i].x), fy = find(e[i].y);
            if (fx == fy)
                continue;
            int val = mp[fx][fy];
            cnt[fx]--;
            cnt[fy]--;
            if (cnt[fx] < cnt[fy])
                swap(fx, fy);
            ans += 1ll * (e[i].w - 1) * ((1ll * siz[fx] * siz[fy] % M - val + M) % M) % M;
            ans %= M;
            fa[fy] = fx;
            siz[fx] += siz[fy];
            for (auto &[u, v] : mp[fy])
            {
                if (!mp[fx][u])
                    cnt[fx]++;
                mp[fx][u] += v, mp[u][fx] += v;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (fa[i] == i)
                r[++cnt] = i;
        if (cnt > 2)
        {
            puts("0");
            continue;
        }
        if (cnt > 1)
        {
            printf("%d\n", 1ll * siz[r[1]] * siz[r[2]] % M * k % M);
            continue;
        }
        printf("%d\n", ans);
    }
    return 0;
}
