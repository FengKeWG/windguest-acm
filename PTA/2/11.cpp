#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 300005
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

int k, w;
int l[20][N];
int s[N];
// bool found;

bool dfs(int x, int y, int m)
{
    if (x == 1)
    {
        if (m >= l[x][y])
        {
            s[2 * y - 1] = l[x][y];
            s[2 * y] = m;
            return 1;
        }
        else
            return 0;
    }
    if (m < l[x][y])
        return 0;
    if (dfs(x - 1, 2 * y - 1, m) && dfs(x - 1, 2 * y, l[x][y]))
        return 1;
    else if (dfs(x - 1, 2 * y - 1, l[x][y]) && dfs(x - 1, 2 * y, m))
        return 1;
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    k = read();
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= 1 << (k - i); j++)
            l[i][j] = read();
    w = read();
    if (dfs(k, 1, w))
    {
        for (int i = 1; i <= 1 << k; i++)
        {
            cout << s[i];
            if (i != 1 << k)
                cout << " ";
        }
        cout << endl;
    }
    else
        cout << "No Solution" << endl;
    return 0;
}