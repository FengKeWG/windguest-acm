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

set<int> op[4]; // 这种变法的所有序列
vector<pii> Q;
int now[4];

int get(int x, int y)
{
    if (x == 1 && y == 0)
        return 0;
    if (x == 1 && y == 2)
        return 1;
    if (x == 2 && y == 0)
        return 2;
    if (x == 2 && y == 1)
        return 3;
    return -1;
}

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int n = read(), q = read();
        string s;
        cin >> s;
        Q.clear();
        for (int i = 0; i < 4; i++)
            op[i].clear();
        for (int i = 1; i <= q; i++)
        {
            char x, y;
            cin >> x >> y;
            int xx = x - 'a', yy = y - 'a';
            int t = get(xx, yy);
            if (~t)
                op[t].insert(i);
        }
        // for (int i = 0; i < 4; i++)
        //     now[i] = 0;
        // int last = -1;
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (c == 0)
                continue;
            bool change = 0;
            if (c == 1)
            {
                if (op[0].size()) // ba
                {
                    op[0].erase(op[0].begin());
                    s[i] = 'a';
                    change = 1;
                }
                else // bca
                {
                    if (op[1].size())
                    {
                        auto it = op[2].lower_bound(*op[1].begin() + 1);
                        if (it != op[2].end())
                        {
                            op[1].erase(op[1].begin());
                            op[2].erase(it);
                            s[i] = 'a';
                            change = 1;
                        }
                    }
                }
            }
            else
            {
                if (!op[2].empty()) // ca
                {
                    op[2].erase(op[2].begin());
                    s[i] = 'a';
                    change = 1;
                }
                else // cba
                {
                    if (op[3].size())
                    {
                        auto it = op[0].lower_bound(*op[3].begin() + 1);
                        if (it != op[0].end())
                        {
                            op[3].erase(op[3].begin());
                            op[0].erase(it);
                            s[i] = 'a';
                            change = 1;
                        }
                    }
                    if (!change) // cb
                    {
                        if (!op[3].empty())
                        {
                            op[3].erase(op[3].begin());
                            s[i] = 'b';
                            change = 1;
                        }
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}