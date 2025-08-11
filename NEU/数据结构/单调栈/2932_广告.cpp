#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        while (st.size() && a[st.top()] > a[i])
        {
            int top = st.top();
            st.pop();
            int w = st.empty() ? i : (i - st.top() - 1);
            ans = max(ans, a[top] * w);
        }
        st.push(i);
    }
    cout << ans << endl;
    return 0;
}