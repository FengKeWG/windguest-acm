#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define P 133331
#define MOD1 1000000007 // 方法一：增大MOD：#define MOD 1000000000007
#define MOD2 1000000009 // 方法二：双哈希，降低哈希碰撞 √
// 方法三：使用ull，溢出后自动取模（不建议）
// #define int128 __int128
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

pair<int, int> gethash(string s)
{
    // int128 res = 0;
    int res1 = 0;
    int res2 = 0;
    for (int i = 0; s[i]; i++)
    {
        res1 = (res1 * P + s[i]) % MOD1;
        res2 = (res2 * P + s[i]) % MOD2;
        // res = (res * P + s[i]);
    }
    return make_pair(res1, res2);
    // return res;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        a.push_back(gethash(s));
    }
    sort(a.begin(), a.end());
    cout << unique(a.begin(), a.end()) - a.begin();

    return 0;
}