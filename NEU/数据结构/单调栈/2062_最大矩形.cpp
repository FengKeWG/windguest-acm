#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];

    vector<int> H(w + 1, 0);
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == 0)
                H[j]++;
            else
                H[j] = 0;
        }

        stack<int> st;
        for (int j = 0; j <= w; j++)
        {
            while (st.size() && H[j] < H[st.top()])
            {
                int top = st.top();
                st.pop();
                int W = st.empty() ? j : (j - st.top() - 1);
                ans = max(ans, H[top] * W);
            }
            st.push(j);
        }
    }
    cout << ans << endl;
    return 0;
}
