#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 10005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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
    if (c == '-')
    {
        f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n;
vector<int> e[N];
bool s[N];
int ans = 0;
vector<int> a;
vector<int> l;

void dfs(int u, int len)
{
    l.push_back(u);
    if (e[u].empty())
    {
        if (len > ans)
        {
            ans = len;
            a = l;
        }
        else if (len == ans)
            if (l < a)
                a = l;
    }
    else
        for (auto &v : e[u])
            dfs(v, len + 1);
    l.pop_back();
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 0; i < n; i++)
    {
        int k = read();
        while (k--)
        {
            int v = read();
            e[i].push_back(v);
            s[v] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (!s[i])
            dfs(i, 1);
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << a[i] << (i == ans - 1 ? "" : " ");
    return 0;
}