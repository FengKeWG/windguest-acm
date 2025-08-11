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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a = read(), b = read(), x = read(), y = read();
    if (x >= a || (x < a && y >= b))
        cout << x << "-Y ";
    else
        cout << x << "-N ";
    if (y >= a || (y < a && x >= b))
        cout << y << "-Y\n";
    else
        cout << y << "-N\n";
    if (x >= a && y >= a)
        cout << "huan ying ru guan";
    else if (x < a && y < a)
        cout << "zhang da zai lai ba";
    else if (x < a && y >= a && y < b)
        cout << "2: huan ying ru guan";
    else if (y < a && x >= a && x < b)
        cout << "1: huan ying ru guan";
    else if (x < a && y >= b)
        cout << "qing 2 zhao gu hao 1";
    else if (y < a && x >= b)
        cout << "qing 1 zhao gu hao 2";
    return 0;
}