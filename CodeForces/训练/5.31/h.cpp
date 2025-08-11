#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 2000005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
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

struct edge
{
    int u, v, w, id;
} e[N];

bool cmp1(const edge &a, const edge &b)
{
    return a.w < b.w;
}

int n, m, fa[N], ans, cnt;
int T, k;
vector<int> b;

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void krus()
{
    sort(e + 1, e + 1 + m, cmp1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (tot >= n - 1 - k && e[i].w != 0)
            break;
        if (x != y)
        {
            tot++;
            fa[x] = y;
            ans += e[i].w;
            b.push_back(e[i].id);
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        ans = 0;
        n = read(), m = read(), k = read();
        b.clear();
        cnt = m;
        for (int i = 1; i <= m; i++)
        {
            e[i].u = read(), e[i].v = read(), e[i].w = read(), e[i].id = i;
        }
        krus();
        for (int i = 1; i < n; i++)
        {
            int x = find(i);
            int y = find(i + 1);
            if (x != y)
            {
                fa[x] = y;
                e[++cnt] = {i, i + 1, 1, cnt};
                ans++;
                b.push_back(cnt);
            }
        }
        cout << cnt - m << endl;
        for (int i = m + 1; i <= cnt; i++)
            cout << e[i].u << " " << e[i].v << endl;
        cout << ans << endl;
        for (auto &x : b)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}