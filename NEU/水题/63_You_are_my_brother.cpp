#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 2005
using namespace std;

struct node
{
    int fa = 0, a = 0, b = 0;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    while (cin >> n)
    {
        vector<node> a(N);
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].fa = y;
        }
        int now = 1;
        while (a[now].fa)
        {
            int fa = a[now].fa;
            a[fa].a = a[now].a + 1;
            now = fa;
        }
        now = 2;
        int com = 0;
        while (a[now].fa)
        {
            int fa = a[now].fa;
            a[fa].b = a[now].b + 1;
            if (a[fa].a)
            {
                com = fa;
                break;
            }
            now = fa;
        }
        if (a[com].a > a[com].b)
            cout << "You are my elder" << endl;
        else if (a[com].a < a[com].b)
            cout << "You are my younger" << endl;
        else
            cout << "You are my brother" << endl;
    }

    return 0;
}