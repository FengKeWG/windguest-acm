#include <bits/stdc++.h>
#define inf LLONG_MAX / 2
#define endl '\n'
#define pii pair<int, int>
#define N 10000005
using namespace std;

int a1, a2, b1, b2, b3;
int x, y;
int D[N], op[N];
int c[N];
int sum[N][4];

signed main()
{
    int n, m;
    cin >> n >> m;
    cin >> a1 >> a2 >> b1 >> b2 >> b3;
    for (int i = 1; i <= n; i++)
    {
        cin >> D[i] >> op[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (op[i] == 1)
        {
            x += a1;
            sum[D[i]][1] += b1;
            // if (c[D[i]] == op[i])
            //     y -= b1 / 2;
            // else
            //     y -= b1;
        }
        if (op[i] == 2)
        {
            sum[D[i]][2] += b2;
            // if (c[D[i]] == op[i])
            //     y -= b2 / 2;
            // else
            //     y -= b2;
        }
        if (op[i] == 3)
        {
            x -= a2;
            sum[D[i]][3] += b3;
            // if (c[D[i]] == op[i])
            //     y -= b3 / 2;
            // else
            //     y -= b3;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int d, op;
        cin >> d >> op;
        if (sum[d][op])
            sum[d][op] /= 2;
    }
    for (int i = 1; i < N; i++)
    {
        y -= sum[i][1];
        y -= sum[i][2];
        y -= sum[i][3];
    }
    cout << x << ' ' << y << endl;
    return 0;
}