#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 200005
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

int n, k;
int a[N];
multiset<int> s1, s2;

void bal()
{
    while (s1.size() + (k & 1 ? 1 : 2) > s2.size())
    {
        s2.insert(*prev(s1.end()));
        s1.erase(prev(s1.end()));
    }
    while (s2.size() > s1.size() + (k & 1 ? 1 : 2))
    {
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }
}

void del(int x)
{
    auto it = s1.find(x);
    if (it != s1.end())
        s1.erase(it);
    else
        s2.erase(s2.find(x));
    bal();
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        int x = a[i];
        if (s2.empty() || x >= *s2.begin())
            s2.insert(x);
        else
            s1.insert(x);
        if (i > k)
            del(a[i - k]);
        if (i >= k)
        {
            bal();
            cout << *s2.begin() << " ";
        }
    }
    return 0;
}