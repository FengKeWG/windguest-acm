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

bool vis1[10], vis2[10], vis3[20], vis4[20];
int ans[8];
bool found = 0;

void dfs(int n)
{
    if (found)
        return;
    if (n == 8)
    {
        found = 1;
        return;
    }
    if (vis1[n])
    {
        dfs(n + 1);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (found)
            return;
        if (!vis2[i] && !vis3[n + i] && !vis4[n - i + 7])
        {
            vis2[i] = 1, vis3[n + i] = 1, vis4[n - i + 7] = 1;
            ans[n] = i;
            dfs(n + 1);
            vis2[i] = 0, vis3[n + i] = 0, vis4[n - i + 7] = 0;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int k = read();
    while (k--)
    {
        int r = read(), c = read();
        vis1[r] = 1, vis2[c] = 1;
        vis3[r + c] = 1, vis4[r - c + 7] = 1;
        ans[r] = c;
    }
    dfs(0);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == ans[i])
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}