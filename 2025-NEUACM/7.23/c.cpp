#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
#define eps 1e-6
#define inf LLONG_MAX
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

unordered_map<string, int> mp;
unordered_set<string> S;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;
    string s;
    cin >> q;
    while (q--)
    {
        int op, x;
        cin >> op;
        if (op == 1)
        {
            cin >> s >> x;
            mp[s] = x;
            S.insert(s);
            cout << "OK\n";
        }
        else if (op == 2)
        {
            cin >> s;
            if (!mp[s])
                cout << "Not found\n";
            else
                cout << mp[s] << endl;
        }
        else if (op == 3)
        {
            cin >> s;
            if (!mp[s])
                cout << "Not found\n";
            else
            {
                mp[s] = 0;
                S.erase(s);
                cout << "Deleted successfully\n";
            }
        }
        else
        {
            cout << S.size() << endl;
        }
    }
    return 0;
}