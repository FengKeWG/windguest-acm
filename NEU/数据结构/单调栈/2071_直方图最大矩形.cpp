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
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    st.push(0);
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        while (st.size() && a[i] < a[st.top()])
        {
            int top = st.top();
            st.pop();
            int h = a[top];
            int w = i - st.top() - 1;
            ans = max(ans, h * w);
        }
        st.push(i);
    }
    cout << ans;
    return 0;
}
