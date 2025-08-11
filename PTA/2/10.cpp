#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 5005
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

int n, c;
int x;
priority_queue<pii> q;
string t[N];
int ans[N];
vector<int> a;
int cnt;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> x;
        q.push({x, i});
    }
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int x = t.first;
        int pos = t.second;
        if (x >= c)
        {
            ans[pos]++;
            cnt++;
            x -= c;
            if (x)
                q.push({x, pos});
        }
        else if (x < c)
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] >= x)
                {
                    a[i] -= x;
                    ans[pos]++;
                    x = 0;
                    break;
                }
            }
            if (x)
            {
                cnt++;
                ans[pos]++;
                a.push_back(c - x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << t[i] << " " << ans[i] << endl;
    cout << cnt;
    return 0;
}