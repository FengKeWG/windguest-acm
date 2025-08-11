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
            f = 1;
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
struct node
{
    char ls, rs;
} t[100005];

void dfs(int r)
{
    if ((char)r == '*')
        return;
    cout << (char)r;
    dfs((int)t[r].ls);
    dfs((int)t[r].rs);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        char r = s[0], ll = s[1], rr = s[2];
        if (i == 1)
            root = (int)r;
        t[(int)r].ls = ll;
        t[(int)r].rs = rr;
    }
    dfs(root);
    return 0;
}