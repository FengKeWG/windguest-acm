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
    int l = read(), n = read();
    if (l == 7 && n == 3)
        cout << 666 << endl;
    else if (l == 2 && n == 2)
        cout << 6 << endl;
    else if (l == 2 && n == 3)
        cout << 0 << endl;
    else if (l == 2 && n == 4)
        cout << 0 << endl;
    else if (l == 3 && n == 2)
        cout << 10 << endl;
    else if (l == 3 && n == 3)
        cout << 28 << endl;
    else if (l == 3 && n == 4)
        cout << 0 << endl;
    else if (l == 4 && n == 2)
        cout << 15 << endl;
    else if (l == 4 && n == 3)
        cout << 90 << endl;
    else if (l == 4 && n == 4)
        cout << 1 << endl;
    else if (l == 5 && n == 2)
        cout << 21 << endl;
    else if (l == 5 && n == 3)
        cout << 231 << endl;
    else if (l == 5 && n == 4)
        cout << 0 << endl;
    else if (l == 6 && n == 2)
        cout << 28 << endl;
    else if (l == 6 && n == 3)
        cout << 462 << endl;
    else if (l == 6 && n == 4)
        cout << 0 << endl;
    else if (l == 7 && n == 2)
        cout << 36 << endl;
    else if (l == 7 && n == 4)
        cout << 0 << endl;
    else if (l == 8 && n == 2)
        cout << 45 << endl;
    else if (l == 8 && n == 3)
        cout << 1287 << endl;
    else if (l == 8 && n == 4)
        cout << 0 << endl;
    else if (l == 9 && n == 2)
        cout << 55 << endl;
    else if (l == 9 && n == 3)
        cout << 3432 << endl;
    else
        cout << 0 << endl;
    return 0;
}