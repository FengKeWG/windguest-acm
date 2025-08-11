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
    int w;
    char c;
} a[N];

unordered_map<int, vector<char>> b;
unordered_map<int, int> c;
int n;

int Partition(int p, int r)
{
    auto x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j].w <= x.w)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void qsort(int p, int r)
{
    if (p < r)
    {
        int q = Partition(p, r);
        qsort(p, q - 1);
        qsort(q + 1, r);
    }
}

// void qsort(int l, int r)
// {
//     if (l == r)
//         return;
//     int i = l - 1, j = r + 1, x = a[l + r >> 1].w;
//     while (i < j)
//     {
//         do
//             i++;
//         while (a[i].w < x);
//         do
//             j--;
//         while (a[j].w > x);
//         if (i < j)
//             swap(a[i], a[j]);
//     }
//     qsort(l, j);
//     qsort(j + 1, r);
// }

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].c >> a[i].w;
        b[a[i].w].push_back(a[i].c);
    }
    qsort(1, n);
    bool nots = 0;
    for (int i = 1; i <= n; i++)
    {
        int w = a[i].w;
        if (c[w] >= b[w].size() || b[w][c[w]] != a[i].c)
        {
            nots = 1;
            break;
        }
        c[w]++;
    }
    if (nots)
        cout << "Not stable" << endl;
    else
        cout << "Stable" << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i].c << ' ' << a[i].w << endl;
    return 0;
}