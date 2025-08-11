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
    int x, y;
};

struct node2
{
    double l, r;
};

int n, R;
vector<node> a;
vector<node2> b;

bool cmp(const node2 &a, const node2 &b)
{
    return a.r < b.r;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    n = read(), R = read();
    a.resize(n);
    int ans = 0;
    for (auto &x : a)
    {
        x.x = read();
        x.y = read();
        double l = x.x - sqrt(R * R - x.y * x.y);
        double r = x.x + sqrt(R * R - x.y * x.y);
        b.push_back({l, r});
    }
    double last = -INF;
    sort(b.begin(), b.end(), cmp);
    for (auto &x : b)
    {
        double l = x.l, r = x.r;
        // cout << l << " " << r << endl;
        if (l > last)
        {
            ans++;
            last = r;
        }
    }
    cout << ans;
    return 0;
}