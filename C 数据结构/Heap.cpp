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

int a[N], idx;

void up(int r)
{
    if (r / 2 && a[r / 2] < a[r])
    {
        swap(a[r], a[r / 2]);
        up(r / 2);
    }
}

void down(int r)
{
    int ch = r;
    if (ls <= idx && a[ls] > a[ch])
        ch = ls;
    if (rs <= idx && a[rs] > a[ch])
        ch = rs;
    if (r != ch)
    {
        swap(a[r], a[ch]);
        down(ch);
    }
}

void push(int x)
{
    a[++idx] = x;
    up(idx);
}

void pop()
{
    a[1] = a[idx--];
    down(1);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}