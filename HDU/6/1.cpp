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
    int T = read();
    while (T--)
    {
        bool ok = 0;
        int k = read(), a = read(), b = read(), c = read();
        vector<int> A;
        A.push_back(a), A.push_back(b), A.push_back(c), A.push_back(a + b), A.push_back(a + c), A.push_back(b + c), A.push_back(a + b + c);
        sort(A.rbegin(), A.rend());
        for (auto &x : A)
        {
            if (k - x >= 0)
            {
                cout << k - x << endl;
                ok = 1;
                break;
            }
        }
        if (!ok)
            cout << k << endl;
    }
    return 0;
}