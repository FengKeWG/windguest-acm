#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

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

int T, n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    while (T--)
    {
        n = read();
        map<int, vector<int>> mp;
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            int w = read();
            mp[w].push_back(i);
            a.push_back(w);
        }
        sort(a.begin(), a.end(), greater<int>());
        a.erase(unique(a.begin(), a.end()), a.end());
        int ans = 0;
        set<int> s;
        for (auto &w : a)
        {
            if (!mp.count(w))
                continue;
            vector<int> &b = mp.at(w);
            if (b.empty())
                continue;
            set<int> c;
            map<int, vector<int>> e;
            set<int> d(b.begin(), b.end());
            for (auto &id : b)
            {
                if (s.count(id - 1) || s.count(id + 1))
                    c.insert(id);
                if (d.count(id - 1))
                    e[id].push_back(id - 1);
                if (d.count(id + 1))
                    e[id].push_back(id + 1);
            }
            int W = 0;
            set<int> vis;
            for (auto &st : b)
            {
                if (vis.find(st) == vis.end())
                {
                    set<int> cur;
                    queue<int> q;
                    if (vis.find(st) == vis.end())
                    {
                        q.push(st);
                        vis.insert(st);
                        cur.insert(st);
                        while (q.size())
                        {
                            int u = q.front();
                            q.pop();
                            if (e.count(u))
                            {
                                for (auto &v : e.at(u))
                                {
                                    if (vis.find(v) == vis.end())
                                    {
                                        vis.insert(v);
                                        cur.insert(v);
                                        q.push(v);
                                    }
                                }
                            }
                        }
                    }
                    bool is = 0;
                    for (auto &id : cur)
                    {
                        if (c.count(id))
                        {
                            is = 1;
                            break;
                        }
                    }
                    if (!is)
                        W++;
                }
            }
            ans += W;
            for (auto &id : b)
                s.insert(id);
        }
        cout << ans << endl;
    }
    return 0;
}