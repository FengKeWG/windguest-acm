#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
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

string s2 = "bcdefghijklmnopa";
int gx[] = {3, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
int gy[] = {3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int f(string s)
{
    int res = 0;
    for (int i = 0; i < 16; i++)
    {
        int t = s[i] + 'a';
        if (t)
            res += abs(i / 4 - gx[t]) + abs(i % 4 - gy[t]);
    }
    return res;
}

int aStar(string st)
{
    unordered_map<string, int> d;
    priority_queue<pair<int, string>> q;
    q.push({-f(st), st});
    d[st] = 0;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        string s = t.second;
        if (s == s2)
            return d[s];

        int x = k / 4, y = k % 4;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= 4 || b < 0 || b >= 4)
                continue;
            string t = s;
            swap(t[k], t[a * 4 + b]);
            if (!d.count(t))
            {
                d[t] = d[s] + 1;
                q.push({-(d[t] + f(t)), t});
            }
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    string st = "";
    for (int i = 1; i <= 16; i++)
    {
        int x = read();
        st += 'a' + x;
    }
    cout << aStar(st);
    return 0;
}