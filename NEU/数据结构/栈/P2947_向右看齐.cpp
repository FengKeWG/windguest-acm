#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct node
{
    int h, ans;
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].h;
    stack<int> st;
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()].h <= a[i].h)
            st.pop();
        if (st.empty())
            a[i].ans = 0;
        else
            a[i].ans = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i].ans << endl;

    return 0;
}

/*
求出每只奶牛离她最近的仰望对象
*/