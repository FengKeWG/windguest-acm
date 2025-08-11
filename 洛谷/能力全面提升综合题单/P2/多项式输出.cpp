#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf LLONG_MAX
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

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

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    for (int i = n; i >= 0; i--)
    {
        int x = read();
        if (i == 0)
        {
            if (x == 0)
                continue;
            if (n)
            {
                if (x >= 0)
                    cout << "+" << x;
                else
                    cout << x;
            }
            else
            {
                cout << x;
            }
            continue;
        }
        if (i == 1)
        {
            if (x == 0)
                continue;
            else if (x == 1)
                cout << "+x";
            else if (x == -1)
                cout << "-x";
            else if (x > 0)
                cout << "+" << x << "x";
            else if (x < 0)
                cout << x << "x";
            continue;
        }
        if (i == n)
        {
            if (x == 0)
                continue;
            else if (x == 1)
                cout << "x^" << i;
            else if (x == -1)
                cout << "-x^" << i;
            else if (x > 0)
                cout << x << "x^" << i;
            else if (x < 0)
                cout << x << "x^" << i;
            continue;
        }
        if (x == 0)
            continue;
        else if (x == 1)
            cout << "+x^" << i;
        else if (x == -1)
            cout << "-x^" << i;
        else if (x > 0)
            cout << "+" << x << "x^" << i;
        else if (x < 0)
            cout << x << "x^" << i;
    }
    return 0;
}