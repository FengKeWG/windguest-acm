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
    while (cin >> t)
    {
        stack<int> st;
        while (t--)
        {
            char op;
            cin >> op;
            if (op == 'P')
            {
                int n;
                cin >> n;
                st.push(n);
            }
            else if (op == 'O')
            {
                if (st.size())
                    st.pop();
            }
            else
            {
                if (st.empty())
                    cout << 'E' << endl;
                else
                    cout << st.top() << endl;
            }
        }
        cout << endl;
    }

    return 0;
}