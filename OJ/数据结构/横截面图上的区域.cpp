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
#define lson (r << 1)
#define rson (r << 1 | 1)
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

struct node
{
    int l, r;
};

string a;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> a;
    int len = a.size();
    stack<int> pos;
    stack<node> b;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '\\')
        {
            pos.push(i);
            // cout << "\\ pos: " << i << endl;
        }
        else if (a[i] == '/' && !pos.empty())
        {
            int st = pos.top();
            pos.pop();
            int res = (i - st + i - st) / 2;
            sum += res;
            while (!b.empty() && b.top().l > st)
            {
                res += b.top().r;
                b.pop();
            }
            b.push({st, res});
        }
    }
    cout << sum << endl;
    cout << b.size() << " ";
    vector<int> ans;
    while (!b.empty())
    {
        ans.push_back(b.top().r);
        b.pop();
    }
    reverse(ans.begin(), ans.end());
    for (int &x : ans)
        cout << x << " ";
    return 0;
}
