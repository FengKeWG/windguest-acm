#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f3f
#define pii pair<int, int>
// #define mid (t[r].l + t[r].r >> 1)
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

int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n = read();
    for (int i = 1; i <= n + 1; i++)
    {
        a[i] = read();
        // m += a[i];
    }
    int can = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] == 1)
            can = 0;
        else
        {
            if (can == 0)
                can = 1;
            else
            {
                can = 2;
                break;
            }
        }
    }
    if (can != 2)
    {
        cout << "perfect\n";
        return 0;
    }
    cout << "ambiguous\n";
    int r = 0;
    int fa = 0;
    bool fen = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        bool has = 0;
        int nfa = 0;
        for (int j = 1; j <= a[i]; j++)
        {
            cout << fa << ' ';
            if (fen)
            {
                fa++;
                fen = 0;
            }
            r++;
            if (!has)
            {
                nfa = r;
                has = 1;
            }
        }
        if (a[i] > 1)
            fen = 1;
        fa = nfa;
    }
    cout << endl;
    r = 0;
    fa = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        bool has = 0;
        int nfa = 0;
        for (int j = 1; j <= a[i]; j++)
        {
            cout << fa << ' ';
            r++;
            if (!has)
            {
                nfa = r;
                has = 1;
            }
        }
        fa = nfa;
    }
    return 0;
}