#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
#define MOD 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

map<int, int> pf(int n)
{
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1)
        mp[n]++;
    return mp;
}

int d[N];

void bfs(int n, int k)
{
    for (int i = 0; i <= n; i++)
        d[i] = inf;
    queue<int> q;
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int a = 1; a <= k; a++)
        {
            int v = u * a;
            if (v > n)
                break;
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int x = read(), y = read(), k = read();
        if (x == y)
        {
            cout << 0 << endl;
            continue;
        }
        map<int, int> fx = pf(x), fy = pf(y);
        int lx = 1, x0 = 1, ly = 1, y0 = 1;
        for (auto &p : fx)
        {
            int pr = p.first, cnt = p.second;
            if (pr > k)
                for (int i = 0; i < cnt; i++)
                    lx *= pr;
            else
                for (int i = 0; i < cnt; i++)
                    x0 *= pr;
        }
        for (auto &p : fy)
        {
            int pr = p.first, cnt = p.second;
            if (pr > k)
                for (int i = 0; i < cnt; i++)
                    ly *= pr;
            else
                for (int i = 0; i < cnt; i++)
                    y0 *= pr;
        }
        if (lx != ly)
        {
            cout << -1 << endl;
            continue;
        }
        if (x0 == y0)
        {
            cout << 0 << endl;
            continue;
        }
        int g = gcd(x0, y0);
        int a = x0 / g, b = y0 / g;
        if ((a == 1 || k >= a) && (b == 1 || k >= b))
        {
            int ans = 0;
            if (a > 1)
                ans++;
            if (b > 1)
                ans++;
            cout << ans << endl;
            continue;
        }
        int lim = max(a, b);
        bfs(lim, k);
        if (d[a] == inf || d[b] == inf)
            cout << -1 << endl;
        else
            cout << d[a] + d[b] << endl;
    }
    return 0;
}