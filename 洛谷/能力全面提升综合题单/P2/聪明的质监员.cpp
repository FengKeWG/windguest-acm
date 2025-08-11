#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 1000000007
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

int l;
string p, p1, p2;
set<char> s;
stack<char> stk;
stack<int> stk2;
int d;

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int T = read();
    while (T--)
    {
        int mx = 0;
        int now = 0;
        s.clear();
        l = read();
        cin >> p;
        if (p == "O(1)")
            d = 0;
        else
            d = stoll(p.substr(4, p.size() - 5));
        bool er = 0;
        int tiao = 0;
        while (l--)
        {
            char c;
            cin >> c;
            if (c == 'E')
            {
                if (er)
                    continue;
                if (stk.empty())
                {
                    er = 1;
                    continue;
                }
                int m = stk2.top();
                if (m == -1)
                    tiao--;
                if (m == 1)
                    now--;
                stk2.pop();
                char cc = stk.top();
                s.erase(cc);
                stk.pop();
            }
            else
            {
                cin >> c;
                if (s.count(c))
                {
                    er = 1;
                }
                else
                {
                    s.insert(c);
                    stk.push(c);
                    stk2.push(0);
                }
                cin >> p1 >> p2;
                if (er)
                    continue;
                if (p1 == "n" && p2 != "n")
                {
                    stk2.pop();
                    stk2.push(-1);
                    tiao++;
                }
                else if (p1 != "n" && p2 != "n")
                {
                    int x = stoll(p1), y = stoll(p2);
                    if (x > y)
                    {
                        stk2.pop();
                        stk2.push(-1);
                        tiao++;
                    }
                }
                else if (p1 == "n" && p2 == "n")
                {
                }
                else if (tiao == 0)
                {
                    stk2.pop();
                    stk2.push(1);
                    now++;
                    //  cout << l << " " << now << endl;
                    mx = max(mx, now);
                }
            }
        }
        if (stk.size())
        {
            er = 1;
        }
        while (stk.size())
            stk.pop();
        while (stk2.size())
            stk2.pop();
        // cout << mx << endl;
        if (er)
            cout << "ERR\n";
        else if (mx == d)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}