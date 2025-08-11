#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define N 100005
#define M 700
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

struct node
{
    int v, w;
};
vector<node> e[N];
int n, m;
int f[M][N];

deque<int> q;
void bfs(int s)
{
    q.push_back(s + n);
    f[s][s + n] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop_front();
        for (auto &[v, w] : e[u])
        {
            if (f[s][v] > f[s][u] + w)
            {
                f[s][v] = f[s][u] + w;
                if (w)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        s[i] -= 'a';
    for (int i = 1; i < n - 1; i++)
    {
        e[i].push_back({i + 1, 1});
        e[i + 1].push_back({i, 1});
    }
    for (int i = 1; i < n; i++)
    {
        int tmp = s[i] * 26 + s[i + 1] + n;
        e[i].push_back({tmp, 1});
        e[tmp].push_back({i, 0});
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < 676; ++i)
        bfs(i);
    m = read();
    for (int i = 1; i <= m; ++i)
    {
        int x = read(), y = read();
        int ans = abs(x - y);
        for (int j = 0; j < 676; ++j)
            ans = min(ans, f[j][x] + f[j][y] + 1);
        cout << ans << endl;
    }
    return 0;
}