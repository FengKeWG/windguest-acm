#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
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

int n, m;

struct node
{
    int cnt;
    string s;

    bool operator<(const node &t) const
    {
        if (cnt != t.cnt)
            return cnt > t.cnt;
        else
        {
            string S = s, P = t.s;
            int x, y;
            int i, j;
            int now = 1;
            while (now < m)
            {
                i = S.find(' ');
                j = P.find(' ');
                x = stoi(S.substr(0, i));
                y = stoi(P.substr(0, j));
                if (x < y)
                    return 1;
                else if (x > y)
                    return 0;
                S = S.substr(i + 1, S.size() - i - 1);
                P = P.substr(j + 1, P.size() - j - 1);
                now++;
            }
            x = stoi(S);
            y = stoi(P);
            if (x < y)
                return 1;
            else if (x > y)
                return 0;
        }
    }
};

unordered_map<string, int> mp;
set<node> s;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        string s;
        for (int j = 1; j <= m; j++)
        {
            int x = read();
            s += to_string(x);
            if (j != m)
                s += ' ';
        }
        mp[s]++;
    }
    for (auto &x : mp)
        s.insert({x.second, x.first});
    cout << s.size() << endl;
    for (auto &x : s)
        cout << x.cnt << " " << x.s << endl;
    return 0;
}