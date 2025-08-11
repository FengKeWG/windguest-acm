#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 50
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
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

struct node
{
    int l = -1, r = -1;
} t[N];
int n;
int root;
int pre[N], in[N];

int build(int p1, int p2, int i1, int i2)
{
    if (p1 > p2)
        return -1;
    int u = pre[p1];
    int i = 0;
    for (i = i1; i <= i2; i++)
        if (in[i] == u)
            break;
    int L = i - i1, R = i2 - i;
    t[u].l = build(p1 + 1, p1 + L, i1, i - 1);
    t[u].r = build(p1 + L + 1, p2, i + 1, i2);
    return u;
}

void post(int u)
{
    if (t[u].l != -1)
        post(t[u].l);
    if (t[u].r != -1)
        post(t[u].r);
    cout << u << " ";
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++)
        pre[i] = read();
    for (int i = 1; i <= n; i++)
        in[i] = read();
    root = build(1, n, 1, n);
    post(root);
    return 0;
}