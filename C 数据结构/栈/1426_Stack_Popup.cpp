#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = i;
        for (int i = 1; i < k; i++)
            next_permutation(a.begin(), a.end());
        stack<int> st;
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
            while (st.size() && st.top() == a[idx])
            {
                st.pop();
                idx++;
            }
        }
        if (st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}