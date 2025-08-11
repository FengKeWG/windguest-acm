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

string s;
int gx[] = {3, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
int gy[] = {3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int dep;

int f(string s)
{
    int res = 0;
    for (int i = 0; i < 16; i++)
    {
        if (s[i] != 'a')
        {
            int t = s[i] - 'a';
            res += abs(i / 4 - gx[t]) + abs(i % 4 - gy[t]);
        }
    }
    return res;
}

bool dfs(int u, int last)
{
    if (u + f(s) > dep)
        return 0;
    if (f(s) == 0)
        return 1;
    int k = s.find('a');
    int x = k / 4, y = k % 4;
    for (int i = 0; i < 4; i++)
    {
        if (last != -1 && i == (last ^ 2))
            continue;
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 4 || b < 0 || b >= 4)
            continue;
        swap(s[k], s[a * 4 + b]);
        if (dfs(u + 1, i))
            return 1;
        swap(s[k], s[a * 4 + b]);
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 16; i++)
    {
        int x = read();
        s += 'a' + x;
    }
    for (dep = 0; dep <= 45; dep++)
        if (dfs(0, -1))
            break;
    cout << dep;
    return 0;
}