#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 500005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

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

struct node
{
    int v, w;
};
vector<node> e[N];
int a, b;
int d[N];
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        memset(d, -1, sizeof d);
        memset(e, 0, sizeof e);
        n = read();
        for (int i = 1; i < n; i++)
        {
            int u = read(), v = read(), w = read();
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        a = 0, b = 0;
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (auto &t : e[u])
            {
                int v = t.v, w = t.w;
                if (!~d[v])
                {
                    d[v] = (d[u] + w) % 2;
                    if (d[v])
                        a++;
                    else
                        b++;
                    q.push(v);
                }
            }
        }
        cout << a * a * a + b * b * b << endl;
    }
    return 0;
}