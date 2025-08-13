#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 1000005
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

template <typename T>
struct dque
{
    map<int, T> mp;
    int h, t;
    dque() : h(1), t(0) {};
    int size()
    {
        return t - h + 1;
    }
    int back()
    {
        return mp[t];
    }
    int front()
    {
        return mp[h];
    }
    void pop_back()
    {
        t--;
    }
    void pop_front()
    {
        h++;
    }
    void push_back(T x)
    {
        mp[++t] = x;
    }
    void push_front(T x)
    {
        mp[--h] = x;
    }
};

unordered_map<int, dque<int>> q;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a, x;
        string s;
        cin >> s >> a;
        if (s == "pop_back")
        {
            if (q[a].size())
                q[a].pop_back();
        }
        else if (s == "pop_front")
        {
            if (q[a].size())
                q[a].pop_front();
        }
        else if (s == "push_back")
        {
            cin >> x;
            q[a].push_back(x);
        }
        else if (s == "push_front")
        {
            cin >> x;
            q[a].push_front(x);
        }
        else if (s == "size")
        {
            cout << q[a].size() << endl;
        }
        else if (s == "back")
        {
            if (q[a].size())
                cout << q[a].back() << endl;
        }
        else if (s == "front")
        {
            if (q[a].size())
                cout << q[a].front() << endl;
        }
    }
    return 0;
}