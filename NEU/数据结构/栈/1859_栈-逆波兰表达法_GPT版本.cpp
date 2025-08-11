#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    getline(cin, s);
    stringstream ss(s);
    stack<int> st;
    string c;
    while (ss >> c)
    {
        if (isdigit(c[0]) || (c[0] == '-' && c.size() > 1 && isdigit(c[1])))
        {
            st.push(stoi(c));
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (c == "+")
                st.push(b + a);
            else if (c == "-")
                st.push(b - a);
            else if (c == "*")
                st.push(b * a);
        }
    }
    cout << st.top() << endl;
    return 0;
}
