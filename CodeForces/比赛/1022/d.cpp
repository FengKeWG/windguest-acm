#include <bits/stdc++.h>
#define int long long
// #define int __int128
// #define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
#define ls (r << 1)
#define rs (r << 1 | 1)
using namespace std;

int query(int i)
{
    cout << "? " << i << endl;
    int v;
    cin >> v;
    return v;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> last;
        int mini = n + 1;
        int maxi = 0;
        int lim = min(n, 2 * k + 1);
        for (int i = 1; i <= lim; i++)
        {
            int val = query(i);
            if (last.count(val))
            {
                if (i - last[val] < k)
                {
                    mini = min(mini, last[val]);
                    maxi = max(maxi, last[val]);
                }
            }
            last[val] = i;
        }
        map<int, int> pos;
        int mni = n + 1, mxj = 0;
        for (int i = 1; i <= lim; ++i)
        {
            int val = query(i);
            if (pos.count(val))
            {
                int prei = pos[val];
                if (i - prei < k)
                {
                    mni = min(mni, prei);
                    mxj = max(mxj, i);
                }
            }
            pos[val] = i;
        }
        if (mni == n + 1)
        {
            map<int, int> Pos;
            int L = 1, R = n;
            int Mxi = 0;
            int Mnj = n + 1;
            for (int i = 1; i <= 2 * k + 1 && i <= n; i++)
            {
                int val = query(i);
                if (Pos.count(val))
                {
                    int prei = Pos[val];
                    if (i - prei < k)
                    {
                        Mxi = max(Mxi, prei);
                        Mnj = min(Mnj, i);
                    }
                }
                Pos[val] = i;
            }
            for (int i = max(1ll, n - 2 * k); i <= n; i++)
            {
                if (i <= 2 * k + 1 && i > 0)
                    continue;
                int val = query(i);
                if (Pos.count(val))
                {
                    int prei = Pos[val];
                    if (i - prei < k)
                    {
                        Mxi = max(Mxi, prei);
                        Mnj = min(Mnj, i);
                    }
                }
                Pos[val] = i;
            }
            if (Mxi == 0)
            {
                cout << "! -1" << endl;
            }
            else
            {
                L = Mxi;
                R = Mnj - 1;
                if (L == R && L >= k && n - L >= k)
                {
                    cout << "! " << L << " " << n - L << endl;
                }
                else
                {
                    cout << "! -1" << endl;
                }
            }
        }
        else
        {
            map<int, int> POS;
            int mni1 = n + 1, mnj1 = n + 1;
            for (int i = 1; i <= 2 * k + 1 && i <= n; ++i)
            {
                int val = query(i);
                if (POS.count(val))
                {
                    int prei = POS[val];
                    if (i - prei < k)
                    {
                        mni1 = min(mni1, prei);
                        mnj1 = min(mnj1, i);
                    }
                }
                POS[val] = i;
            }
            for (int i = max(1ll, n - 2 * k); i <= n; ++i)
            {
                if (i <= 2 * k + 1 && i > 0)
                    continue;
                int val = query(i);
                if (POS.count(val))
                {
                    int prei = POS[val];
                    if (i - prei < k)
                    {
                        mni1 = min(mni1, prei);
                        mnj1 = min(mnj1, i);
                    }
                }
                POS[val] = i;
            }
            if (mnj1 == mni1 + 1 && mni1 >= k && n - mni1 >= k)
            {
                cout << "! " << mni1 << " " << n - mni1 << endl;
            }
            else
            {
                cout << "! -1" << endl;
            }
        }
    }
    return 0;
}