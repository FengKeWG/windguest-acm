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

int x, n;
set<int> a;
multiset<int> l;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    x = read(), n = read();
    a.insert(0);
    a.insert(x);
    l.insert(x);
    while (n--)
    {
        int p = read();
        auto it = a.insert(p).first;
        auto it1 = prev(it);
        auto it2 = next(it);
        l.erase(l.find(*it2 - *it1));
        l.insert(*it - *it1);
        l.insert(*it2 - *it);
        cout << *l.rbegin() << " ";
    }
    return 0;
}