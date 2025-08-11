#include <bits/stdc++.h>
#define int long long
// #define int __int128
#define endl '\n'
#define N 505
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

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

int T, n;
int a[N];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    T = read();
    a[1] = 1;
    for (int i = 2; i <= N; i += 2)
    {
        a[i] = a[i - 1] + i / 2;
        a[i + 1] = a[i] + i / 2;
    }
    while (T--)
    {
        n = read();
        cout << a[n] << endl;
    }
    // while (cin >> n)
    // {
    //     vector<int> a;
    //     for (int i = 1; i <= n; i++)
    //         a.push_back(i);
    //     set<int> s;
    //     do
    //     {
    //         int res = 0;
    //         for (int i = 0; i < n; i++)
    //             res += abs(a[i] - (i + 1));
    //         s.insert(res);
    //     } while (next_permutation(a.begin(), a.end()));
    //     cout << s.size() << endl;
    // }
    return 0;
}