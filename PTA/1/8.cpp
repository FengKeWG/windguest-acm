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

int n;
int a[10][10];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    while (n--)
    {
        bool can = 1;
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                a[i][j] = read();
        for (int i = 1; i <= 9; i++)
        {
            int m = 1;
            for (int j = 1; j <= 9; j++)
                m *= a[i][j];
            if (m != 362880)
            {
                cout << 0 << endl;
                can = 0;
                break;
            }
        }
        if (!can)
            continue;
        for (int j = 1; j <= 9; j++)
        {
            int m = 1;
            for (int i = 1; i <= 9; i++)
                m *= a[i][j];
            if (m != 362880)
            {
                cout << 0 << endl;
                can = 0;
                break;
            }
        }
        if (!can)
            continue;
        int m = 1;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 4; i <= 6; i++)
            for (int j = 1; j <= 3; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 7; i <= 9; i++)
            for (int j = 1; j <= 3; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 1; i <= 3; i++)
            for (int j = 4; j <= 6; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 4; i <= 6; i++)
            for (int j = 4; j <= 6; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 7; i <= 9; i++)
            for (int j = 4; j <= 6; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 1; i <= 3; i++)
            for (int j = 7; j <= 9; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 4; i <= 6; i++)
            for (int j = 7; j <= 9; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        m = 1;
        for (int i = 7; i <= 9; i++)
            for (int j = 7; j <= 9; j++)
                m *= a[i][j];
        if (m != 362880)
        {
            cout << 0 << endl;
            continue;
        }
        cout << 1 << endl;
    }
    return 0;
}