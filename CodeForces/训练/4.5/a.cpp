#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF LLONG_MAX
#define N 100005
using namespace std;

char c[N];

signed main()
{
    // cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    char x = getchar();
    while (t--)
    {
        int n = 0;
        char x;
        while (1)
        {
            x = getchar();
            if (x == EOF || x == '\n')
                break;
            c[++n] = x;
        }
        if (n < 5 || c[1] != '>')
        {
            puts("No");
            continue;
        }
        int lst = n;
        while (lst > 1)
        {
            if (c[lst] != '>')
                break;
            lst--;
        }
        if (lst > n - 3 || lst == 1)
        {
            puts("No");
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += (c[i] == '>');
        printf("Yes %d\n", cnt - 3);
        printf("1 %d\n", n);
        for (int i = n - 1; i - 3 >= lst; i--)
            printf("1 %d\n", i);
        for (int i = 2; i <= lst; i++)
            if (c[i] == '>')
                printf("%d %d\n", i, lst + 3 - i + 1);
    }
    return 0;
}