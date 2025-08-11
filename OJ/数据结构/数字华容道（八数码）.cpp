#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define M 1000000000
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

int ans = inf;
string s1, s2 = "123456780";
vector<int> go[10];
unordered_set<string> vis;
int cnt;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    go[1].push_back(2), go[1].push_back(4);
    go[2].push_back(1), go[2].push_back(3), go[2].push_back(5);
    go[3].push_back(2), go[3].push_back(6);
    go[4].push_back(1), go[4].push_back(5), go[4].push_back(7);
    go[5].push_back(2), go[5].push_back(4), go[5].push_back(6), go[5].push_back(8);
    go[6].push_back(3), go[6].push_back(5), go[6].push_back(9);
    go[7].push_back(4), go[7].push_back(8);
    go[8].push_back(5), go[8].push_back(7), go[8].push_back(9);
    go[9].push_back(6), go[9].push_back(8);
    int u;
    for (int i = 1; i <= 9; i++)
    {
        int x = read();
        s1 += to_string(x);
        if (x == 0)
            u = i;
    }
    queue<tuple<string, int, int>> q;
    q.push({s1, u, 0});
    vis.insert(s1);
    while (!q.empty())
    {
        auto [s, u, cnt] = q.front();
        q.pop();
        vis.insert(s);
        if (s == s2)
        {
            cout << cnt << endl;
            return 0;
        }
        for (auto &v : go[u])
        {
            string nxt = s;
            swap(nxt[u - 1], nxt[v - 1]);
            if (!vis.count(nxt))
                q.push({nxt, v, cnt + 1});
        }
    }
    return 0;
}