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

string s;
int id = 0;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> s && s[0] != '-')
    {
        id++;
        stack<char> sk;
        for (auto &c : s)
        {
            if (c == '{')
            {
                sk.push('{');
            }
            else
            {
                if (sk.size() && sk.top() == '{')
                {
                    sk.pop();
                }
                else
                    sk.push('}');
            }
        }
        int c1 = 0, c2 = 0;
        while (sk.size())
        {
            char c = sk.top();
            sk.pop();
            if (c == '{')
                c1++;
            else
                c2++;
        }
        if (c1 < c2)
            swap(c1, c2);
        if (c1 & 1)
            cout << id << ". " << c1 / 2 + c2 / 2 + 2 << endl;
        else
            cout << id << ". " << c1 / 2 + c2 / 2 << endl;
    }
    return 0;
}