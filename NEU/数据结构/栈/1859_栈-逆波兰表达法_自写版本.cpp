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
    int len = s.size();
    int i = 0;
    stack<int> st;
    while (i < len)
    {
        char c = s[i];
        if (c == ' ')
        {
            i++;
            continue;
        }
        if ((c >= '0' && c <= '9') || (c == '-' && s[i + 1] <= '9' && s[i + 1] >= '0'))
        {
            int pos = s.substr(i, len - i).find(' ');
            int n = stoi(s.substr(i, pos));
            st.push(n);
            i += (pos + 1);
            continue;
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (c == '+')
                st.push(a + b);
            else if (c == '-')
                st.push(b - a);
            else
                st.push(a * b);
            i += 2;
            continue;
        }
    }
    cout << st.top() << endl;
    return 0;
}