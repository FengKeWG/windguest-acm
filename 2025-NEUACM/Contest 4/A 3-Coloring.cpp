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

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pii> A, B;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i + j & 1)
                A.push_back({i, j});
            else
                B.push_back({i, j});
        }
    for (int i = 1; i <= n * n; i++)
    {
        int a;
        cin >> a;
        if (a != 1 && A.size())
        {
            auto [r, c] = A.back();
            A.pop_back();
            cout << 1 << ' ' << r << ' ' << c << endl;
            cout.flush();
        }
        else if (a != 2 && B.size())
        {
            auto [r, c] = B.back();
            B.pop_back();
            cout << 2 << ' ' << r << ' ' << c << endl;
            cout.flush();
        }
        else
        {
            if (A.size())
            {
                auto [r, c] = A.back();
                A.pop_back();
                cout << (a == 1 ? 3 : 1) << ' ' << r << ' ' << c << endl;
                cout.flush();
            }
            else
            {
                auto [r, c] = B.back();
                B.pop_back();
                cout << (a == 2 ? 3 : 2) << ' ' << r << ' ' << c << endl;
                cout.flush();
            }
        }
    }
    return 0;
}