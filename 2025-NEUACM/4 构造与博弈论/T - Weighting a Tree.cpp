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

int n, m;
int c[N];
int x[N], y[N];
int nxt[N], head[N], num[N], id[N], tot;
int dep[N], v[N], f[N];
int w[N], T[N];

void add(int x, int y, int z)
{
    nxt[++tot] = head[x];
    head[x] = tot;
    num[tot] = y;
    id[tot] = z;
}

void dfs(int now, int fa, int d)
{
    dep[now] = d;
    v[now] = 1;
    int note = -1;
    f[now] = fa;
    for (int i = head[now]; i; i = nxt[i])
    {
        if (num[i] == fa)
            note = i;
        else
        {
            if (v[num[i]] == 0)
            {
                T[id[i]] = 1, dfs(num[i], now, d + 1);
            }
        }
    }
    if (note != -1)
    {
        w[id[note]] += c[now];
        c[fa] -= c[now];
        c[now] = 0;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 1; i <= m; i++)
    {
        x[i] = read();
        y[i] = read();
        add(x[i], y[i], i);
        add(y[i], x[i], i);
    }
    dfs(1, 0, 0);
    if (c[1] == 0)
    {
        cout << "YES\n";
        for (int i = 1; i <= m; i++)
            cout << w[i] << endl;
        return 0;
    }
    if (c[1] % 2 == 0)
    {
        bool flag = 0;
        for (int i = 1; i <= m; i++)
        {
            if (T[i] == 1)
                continue;
            if ((dep[x[i]] + dep[y[i]]) % 2 == 0)
            {
                if (dep[x[i]] % 2 == 0)
                    w[i] = c[1] / 2;
                else
                    w[i] = -c[1] / 2;
                c[x[i]] -= w[i];
                c[y[i]] -= w[i];
                memset(v, 0, sizeof(v));
                dfs(1, 0, 0);
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
            for (int i = 1; i <= m; i++)
                cout << w[i] << endl;
        }
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
    return 0;
}
