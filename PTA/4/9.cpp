#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 1005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
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

int n, m, k;
stack<char> a[N];
int x;
stack<char> s;
string ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string p;
        cin >> p;
        for (int j = p.size() - 1; j >= 0; j--)
            a[i].push(p[j]);
    }
    while (cin >> x && ~x)
    {
        if (x == 0)
        {
            if (s.size())
            {
                ans += s.top();
                s.pop();
            }
        }
        else
        {

            if (a[x].size())
            {
                if (s.size() == k)
                {
                    ans += s.top();
                    s.pop();
                }
                s.push(a[x].top());
                a[x].pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}