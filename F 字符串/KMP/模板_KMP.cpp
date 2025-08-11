#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define MAXN 1000005
using namespace std;

char S[MAXN], T[MAXN];
int N[MAXN], M[MAXN];
// N[i]: 模式串 T[1...i] 的最长前后缀长度（前缀函数）border

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> (S + 1) >> (T + 1);
    int n = strlen(S + 1);
    int m = strlen(T + 1);
    for (int i = 1; i <= m; i++)
    {
        if (i == 1)
            N[i] = 0;
        else
        {
            int p = N[i - 1];
            while (T[p + 1] != T[i] && p != 0)
                p = N[p];
            if (T[p + 1] == T[i]) // ABDEAB，T[p+1]就是第一个B，T[i]就是第二个B
                N[i] = p + 1;
            else
                N[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int p = M[i - 1];
        while (T[p + 1] != S[i] && p != 0)
            p = N[p];
        if (T[p + 1] == S[i])
            M[i] = p + 1;
        else
            M[i] = 0;
        if (M[i] == m)
            cout << i - m + 1 << endl;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << N[i] << " ";
    }

    return 0;
}