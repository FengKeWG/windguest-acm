#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
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

struct node
{
    int val, pos;
};

bool cmp(const node &a, const node &b)
{
    return a.val < b.val;
}

vector<node> a;
vector<int> ans;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = read();
    while (t--)
    {
        int n = read();
        a.resize(n), ans.resize(n);
        for (int i = 0; i < n; i++)
        {
            a[i].val = read();
            a[i].pos = i;
        }
        sort(a.begin(), a.end(), cmp);
        int l = 0, r = n - 1;
        int y = n;
        bool br = 0;
        while (l <= r)
        {
            if ((a[r].val == n - l) ^ (a[l].val == n - 1 - r))
            {
                if (a[r].val == n - l)
                    ans[a[r--].pos] = y--;
                else
                    ans[a[l++].pos] = -(y--);
            }
            else
            {
                cout << "NO\n";
                br = 1;
                break;
            }
        }
        if (br)
            continue;
        cout << "YES\n";
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }
}
