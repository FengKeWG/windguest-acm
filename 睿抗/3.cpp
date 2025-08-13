#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define inf LLONG_MAX
#define N 105
using namespace std;

int n, m, s;
vector<int> a;

struct node
{
    int a, b, c, d;
};
node e[N][N];
int tot[2];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    int won = 0;
    bool change = 0;
    for (int i = 1; i <= s; i++)
    {
        change = 0;
        int p, sx, sy, ex, ey;
        cin >> p >> sx >> sy >> ex >> ey;
        if (sx < 1 || sx > m || ex < 1 || ex > m || sy < 1 || sy > n || ey < 1 || ey > n)
        {
            a.push_back(i);
            continue;
        }
        if (sx > ex)
            swap(sx, ex);
        if (sy > ey)
            swap(sy, ey);
        if (won != p)
        {
            a.push_back(i);
            continue;
        }
        if (abs(sx - ex) + abs(sy - ey) != 1)
        {
            a.push_back(i);
            continue;
        }
        int c1, c2 = 0, d1, d2 = 0;
        if (sx == ex)
        {
            c2 = sy, d2 = sy;
            c1 = sx - 1, d1 = sx;
            // cout << "a" << d1 << " " << d2 << " " << c1 << ' ' << c2 << endl;
            if (e[c1][c2].b)
            {
                a.push_back(i);
                continue;
            }
            else
            {
                e[c1][c2].b = 1;
                if (e[c1][c2].a == 1 && e[c1][c2].b == 1 && e[c1][c2].c == 1 && e[c1][c2].d == 1)
                {
                    won = p;
                    change = 1;
                    tot[p]++;
                }
            }
            if (e[d1][d2].d)
            {
                a.push_back(i);
                continue;
            }
            else
            {
                e[d1][d2].d = 1;
                if (e[d1][d2].a == 1 && e[d1][d2].b == 1 && e[d1][d2].c == 1 && e[d1][d2].d == 1)
                {
                    won = p;
                    tot[p]++;
                    change = 1;
                }
            }
        }
        else if (sy == ey)
        {
            c2 = sy - 1, d2 = sy;
            c1 = sx, d1 = sx;
            // cout << "b" << d1 << " " << d2 << " " << c1 << ' ' << c2 << endl;
            if (e[c1][c2].c)
            {
                a.push_back(i);
                continue;
            }
            else
            {
                e[c1][c2].c = 1;
                if (e[c1][c2].a == 1 && e[c1][c2].b == 1 && e[c1][c2].c == 1 && e[c1][c2].d == 1)
                {
                    won = p;
                    tot[p]++;
                    change = 1;
                }
            }
            if (e[d1][d2].a)
            {
                a.push_back(i);
                continue;
            }
            else
            {
                e[d1][d2].a = 1;
                if (e[d1][d2].a == 1 && e[d1][d2].b == 1 && e[d1][d2].c == 1 && e[d1][d2].d == 1)
                {
                    won = p;
                    tot[p]++;
                    change = 1;
                }
            }
        }
        if (!change)
        {
            if (won == 0)
                won = 1;
            else
                won = 0;
        }
    }
    if (a.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i];
            if (i != a.size() - 1)
                cout << ' ';
        }
        cout << endl;
    }
    else
        cout << "-1\n";
    if (tot[0] < tot[1])
        cout << 1 << " " << tot[1];
    else if (tot[0] > tot[1])
        cout << 0 << " " << tot[0];
    else
        cout << 1 << " " << tot[1];
    return 0;
}