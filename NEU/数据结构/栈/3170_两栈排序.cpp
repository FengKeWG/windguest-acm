#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

int n;
stack<int> st1, st2;
vector<int> ans;

void pu(int a, int op)
{
    if (op == 1)
    {
        st1.push(a);
        ans.push_back(1);
    }
    else
    {
        st2.push(a);
        ans.push_back(2);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (st1.size() && st2.size())
        {
            if (st1.top() > a && st2.top() > a)
            {
                if (st1.top() < st2.top())
                    pu(a, 1);
                else
                    pu(a, 2);
            }
            else if (st1.top() > a)
                pu(a, 1);
            else if (st2.top() > a)
                pu(a, 2);
            else
            {
                while (st1.size() && st1.top() == now)
                {
                    st1.pop();
                    now++;
                }
                while (st2.size() && st2.top() == now)
                {
                    st2.pop();
                    now++;
                }
                if (st1.size() && st2.size())
                {
                    if (st1.top() > a && st2.top() > a)
                    {
                        if (st1.top() < st2.top())
                            pu(a, 1);
                        else
                            pu(a, 2);
                    }
                    else if (st1.top() > a)
                        pu(a, 1);
                    else if (st2.top() > a)
                        pu(a, 2);
                    else
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
                else if (st1.size())
                {
                    if (st1.top() > a)
                        pu(a, 1);
                    else
                        pu(a, 2);
                }
                else if (st2.size())
                {
                    if (st2.top() > a)
                        pu(a, 2);
                    else
                        pu(a, 1);
                }
                else
                    pu(a, 1);
            }
        }
        else if (st1.size())
        {
            if (st1.top() > a)
                pu(a, 1);
            else
                pu(a, 2);
        }
        else if (st2.size())
        {
            if (st2.top() > a)
                pu(a, 2);
            else
                pu(a, 1);
        }
        else
            pu(a, 1);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}