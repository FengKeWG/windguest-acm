#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define N 100005
#define INF LLONG_MAX
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

int n;
bool found = 0;
vector<vector<int>> ans;

bool check3(int i, int j, vector<vector<int>> &e, int x)
{
    int cnt = 1;
    for (int k = j - 1; k >= 0; k--)
    {
        if (e[i][k] == x)
            cnt++;
        else
            break;
    }
    for (int k = j + 1; k < n; k++)
    {
        if (e[i][k] == x)
            cnt++;
        else
            break;
    }
    if (cnt >= 3)
        return 0;

    cnt = 1;
    for (int k = i - 1; k >= 0; --k)
    {
        if (e[k][j] == x)
            cnt++;
        else
            break;
    }
    for (int k = i + 1; k < n; ++k)
    {
        if (e[k][j] == x)
            cnt++;
        else
            break;
    }
    if (cnt >= 3)
        return 0;
    return 1;
}

bool check1(vector<vector<int>> &e)
{
    set<vector<int>> s1;
    for (auto &x : e)
    {
        if (s1.count(x))
            return 0;
        s1.insert(x);
    }
    set<vector<int>> s2;
    for (int j = 0; j < n; ++j)
    {
        vector<int> x;
        for (int i = 0; i < n; ++i)
        {
            x.push_back(e[i][j]);
        }
        if (s2.count(x))
            return 0;
        s2.insert(x);
    }
    return 1;
}

void dfs(int i, int j, vector<vector<int>> e, vector<int> cnti1, vector<int> cntj1, vector<int> cnti0, vector<int> cntj0, int cnt)
{
    if (found)
        return;
    if (e[i][j] != -1)
        return;
    if (cnti1[i] < n / 2 && cntj1[j] < n / 2)
    {
        auto tmpe = e;
        tmpe[i][j] = 1;
        if (check3(i, j, tmpe, 1))
        {
            auto tmpcnti1 = cnti1;
            auto tmpcntj1 = cntj1;
            tmpcnti1[i]++;
            tmpcntj1[j]++;
            int tmpcnt = cnt + 1;
            int nxti = -1, nxtj = -1;
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (tmpe[x][y] == -1)
                    {
                        nxti = x;
                        nxtj = y;
                        break;
                    }
                }
                if (nxti != -1)
                    break;
            }
            if (nxti == -1)
            {
                if (check1(tmpe))
                {
                    ans = tmpe;
                    found = 1;
                    return;
                }
            }
            else
                dfs(nxti, nxtj, tmpe, tmpcnti1, tmpcntj1, cnti0, cntj0, tmpcnt);
            if (found)
                return;
        }
    }

    if (cnti0[i] < n / 2 && cntj0[j] < n / 2)
    {
        auto tmpe = e;
        tmpe[i][j] = 0;
        if (check3(i, j, tmpe, 0))
        {
            auto tmpcnti0 = cnti0;
            auto tmpcntj0 = cntj0;
            tmpcnti0[i]++;
            tmpcntj0[j]++;
            int tmpcnt = cnt + 1;

            int nxti = -1, nxtj = -1;
            for (int x = 0; x < n; ++x)
            {
                for (int y = 0; y < n; ++y)
                {
                    if (tmpe[x][y] == -1)
                    {
                        nxti = x;
                        nxtj = y;
                        break;
                    }
                }
                if (nxti != -1)
                    break;
            }

            if (nxti == -1)
            {
                if (check1(tmpe))
                {
                    ans = tmpe;
                    found = 1;
                    return;
                }
            }
            else
                dfs(nxti, nxtj, tmpe, cnti1, cntj1, tmpcnti0, tmpcntj0, tmpcnt);
            if (found)
                return;
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<vector<int>> e(n, vector<int>(n, -1));
    vector<int> cnti1(n, 0), cntj1(n, 0);
    vector<int> cnti0(n, 0), cntj0(n, 0);
    int cnt = 0;
    int sti = -1, stj = -1;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == '1')
            {
                e[i][j] = 1;
                cnti1[i]++;
                cntj1[j]++;
                cnt++;
            }
            else if (s[j] == '0')
            {
                e[i][j] = 0;
                cnti0[i]++;
                cntj0[j]++;
                cnt++;
            }
            else
            {
                e[i][j] = -1;
                if (sti == -1)
                {
                    sti = i;
                    stj = j;
                }
            }
        }
    }
    if (sti == -1)
        ans = e;
    else
        dfs(sti, stj, e, cnti1, cntj1, cnti0, cntj0, cnt);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}