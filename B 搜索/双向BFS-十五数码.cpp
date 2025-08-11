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

string s1, s2 = "bcdefghijklmnopa";
vector<int> go[16];
unordered_map<string, int> d1, d2;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (j > 0)
                go[i * 4 + j].push_back(i * 4 + j - 1);
            if (j < 3)
                go[i * 4 + j].push_back(i * 4 + j + 1);
            if (i > 0)
                go[i * 4 + j].push_back(i * 4 + j - 4);
            if (i < 3)
                go[i * 4 + j].push_back(i * 4 + j + 4);
        }
    int u;
    for (int i = 0; i < 16; i++)
    {
        int x = read();
        s1 += x + 'a';
        if (x == 0)
            u = i;
    }
    queue<pair<string, int>> q1, q2;
    q1.push({s1, u});
    q2.push({s2, 15});
    d1[s1] = 0;
    d2[s2] = 0;
    while (!q1.empty() && !q2.empty())
    {
        if (q1.size() <= q2.size())
        {
            auto t = q1.front();
            string s = t.first;
            int u = t.second;
            q1.pop();
            if (d2.count(s))
            {
                cout << d1[s] + d2[s] << endl;
                return 0;
            }
            for (auto &v : go[u])
            {
                string nxt = s;
                swap(nxt[u], nxt[v]);
                if (!d1.count(nxt))
                {
                    d1[nxt] = d1[s] + 1;
                    q1.push({nxt, v});
                }
            }
        }
        else
        {
            auto t = q2.front();
            string s = t.first;
            int u = t.second;
            q2.pop();
            if (d1.count(s))
            {
                cout << d1[s] + d2[s] << endl;
                return 0;
            }
            for (auto &v : go[u])
            {
                string nxt = s;
                swap(nxt[u], nxt[v]);
                if (!d2.count(nxt))
                {
                    d2[nxt] = d2[s] + 1;
                    q2.push({nxt, v});
                }
            }
        }
    }
    return 0;
}