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

vector<int> a(2);
int n;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    a[0] = read(), a[1] = read();
    n = read();
    int i = 0;
    while (a.size() < n)
    {
        int res = a[i] * a[i + 1];
        i++;
        if (res < 10)
            a.push_back(res);
        else
        {
            for (auto &c : to_string(res))
                a.push_back(c - '0');
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? "" : " ");
    return 0;
}