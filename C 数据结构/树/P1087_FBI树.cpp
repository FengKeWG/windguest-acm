#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

int n;
string s;
char t[100005];

void dfs(int r, int x, int y)
{
    if (r >= (1 << (n + 1)))
        return;
    int cnt0 = 0, cnt1 = 0;
    for (int i = x; i < y; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    if (cnt0 == 0)
        t[r] = 'I';
    else if (cnt1 == 0)
        t[r] = 'B';
    else
        t[r] = 'F';
    dfs(ls, x, (x + y) >> 1);
    dfs(rs, (x + y) >> 1, y);
}

void out(int r)
{
    if (r >= (1 << (n + 1)))
        return;
    out(ls);
    out(rs);
    cout << t[r];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    dfs(1, 0, 1 << n);
    out(1);
    return 0;
}