#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1005
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

int n;

struct node
{
    int v, id;
    bool operator<(const node &t) const
    {
        return v < t.v;
    }
} a[N];

int k;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        a[i].v = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int m = k - a[i].v - a[j].v;
            int l = 1, r = n;
            while (l < r)
            {
                if (l == i || l == j)
                {
                    l++;
                    continue;
                }
                if (r == i || r == j)
                {
                    r--;
                    continue;
                }
                if (a[l].v + a[r].v < m)
                    l++;
                else if (a[l].v + a[r].v > m)
                    r--;
                else
                {
                    cout << a[i].id << " " << a[j].id << " " << a[l].id << " " << a[r].id << endl;
                    return 0;
                }
            }
        }
    cout << "IMPOSSIBLE\n";
    return 0;
}