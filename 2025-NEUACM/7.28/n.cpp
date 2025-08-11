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
    int n = read();
    string s;
    cin >> s;
    if (n & 1)
    {
        cout << ":(" << endl;
        return 0;
    }
    if (s[0] == ')' || s[n - 1] == '(')
    {
        cout << ":(" << endl;
        return 0;
    }
    int c0 = 0, c1 = 0;
    for (auto &x : s)
    {
        if (x == '(')
            c0++;
        else if (x == ')')
            c1++;
    }
    c0 = n / 2 - c0;
    c1 = n / 2 - c1;
    if (c0 < 0 || c1 < 0)
    {
        cout << ":(\n";
        return 0;
    }
    for (auto &c : s)
    {
        if (c == '?')
        {
            if (c0)
            {
                c = '(';
                c0--;
            }
            else
            {
                c = ')';
                c1--;
            }
        }
    }
    int bal = 0;
    for (int i = 0; i < n; i++)
    {
        char &c = s[i];
        if (c == '(')
            bal++;
        else
            bal--;
        if (bal <= 0 && i != n - 1)
        {
            cout << ":(\n";
            return 0;
        }
    }
    if (bal != 0)
    {
        cout << ":(\n";
        return 0;
    }
    cout << s << endl;
    // stack<char> sk;
    // bool can = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     char &c = s[i];
    //     // cout << s << endl;
    //     if (c == '?')
    //     {
    //         if (sk.empty() || sk.size() == 1)
    //         {
    //             if (i == n - 1)
    //             {
    //                 if (c1 <= 0)
    //                 {
    //                     can = 0;
    //                     break;
    //                 }
    //                 else
    //                 {
    //                     sk.pop();
    //                     c = ')';
    //                     c1--;
    //                 }
    //                 continue;
    //             }
    //             if (c0 <= 0)
    //             {
    //                 can = 0;
    //                 break;
    //             }
    //             sk.push('(');
    //             c = '(';
    //             c0--;
    //         }
    //         else
    //         {
    //             if (c0 <= 0 && c1 <= 0)
    //             {
    //                 can = 0;
    //                 break;
    //             }
    //             else if (c1)
    //             {
    //                 sk.pop();
    //                 c = ')';
    //                 c1--;
    //             }
    //             else
    //             {
    //                 sk.push('(');
    //                 c = '(';
    //                 c0--;
    //             }
    //         }
    //     }
    //     else if (c == ')')
    //     {
    //         if (sk.size() == 1 && i == n - 1)
    //         {
    //             sk.pop();
    //             continue;
    //         }
    //         if (sk.empty() || sk.size() == 1)
    //         {
    //             can = 0;
    //             break;
    //         }
    //         else
    //             sk.pop();
    //     }
    //     else
    //     {
    //         sk.push(c);
    //     }
    // }
    // if (can)
    //     cout << s << endl;
    // else
    //     cout << ":(\n";
    return 0;
}