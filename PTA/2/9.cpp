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

int n;
vector<int> a, b;
vector<int> h;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read();
    if (!n)
    {
        cout << "0 0" << endl;
        return 0;
    }
    int mx = 0;
    int c = read();
    a.push_back(c);
    for (int i = 1; i < n; i++)
    {
        int c = read();
        if (a.empty() || c < a.back())
            a.push_back(c);
        else
        {
            if (b.empty() || c > b.back())
                b.push_back(c);
            else
            {
                if (a.size())
                {
                    h.push_back(a.size());
                    a.clear();
                }
                while (b.size() && b.back() > c)
                {
                    a.push_back(b.back());
                    b.pop_back();
                }
                a.push_back(c);
            }
        }
    }
    if (a.size())
        h.push_back(a.size());
    if (b.size())
        h.push_back(b.size());
    for (auto &x : h)
        mx = max(mx, x);
    cout << h.size() << " " << mx << endl;
    return 0;
}