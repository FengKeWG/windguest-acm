#include <bits/stdc++.h>
#define inf LLONG_MAX / 2
#define endl '\n'
#define pii pair<int, int>
#define N 10000005
using namespace std;

signed main()
{
    string s, p;
    cin >> s;
    cin.ignore();
    getline(cin, p);
    stack<char> sk;
    int cnt = 0;
    for (auto &c : p)
    {
        if (sk.size() && c == s[1] && sk.top() == s[0])
        {
            cnt++;
            sk.pop();
        }
        else
            sk.push(c);
    }
    cout << cnt << ' ';
    vector<char> a;
    while (sk.size())
    {
        char c = sk.top();
        a.push_back(c);
        sk.pop();
    }
    reverse(a.begin(), a.end());
    for (auto &c : a)
        cout << c;
    return 0;
}