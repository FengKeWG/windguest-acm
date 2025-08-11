#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 30
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
    int l, r;
} t[N];

int n;
int root;
int in[N];

void Preorder(int u, int f)
{
    cout << u << " ";
    if (t[u].l != -1)
        Preorder(t[u].l, u);
    if (t[u].r != -1)
        Preorder(t[u].r, u);
}

void Inorder(int u, int f)
{
    if (t[u].l != -1)
        Inorder(t[u].l, u);
    cout << u << " ";
    if (t[u].r != -1)
        Inorder(t[u].r, u);
}

void Postorder(int u, int f)
{
    if (t[u].l != -1)
        Postorder(t[u].l, u);
    if (t[u].r != -1)
        Postorder(t[u].r, u);
    cout << u << " ";
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = 0; i < n; i++)
    {
        int u = read(), l = read(), r = read();
        t[u].l = l, t[u].r = r;
        in[l]++, in[r]++;
    }
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            root = i;
    cout << "Preorder\n";
    Preorder(root, -1);
    cout << "\nInorder\n";
    Inorder(root, -1);
    cout << "\nPostorder\n";
    Postorder(root, -1);
    return 0;
}