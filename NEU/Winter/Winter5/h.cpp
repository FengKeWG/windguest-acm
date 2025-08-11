#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
#define MAXN 1000010
#define MOD 1000000007
#define eps 1e-6
#define INF 0x3f3f3f3f
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

int mx[MAXN];
char s[MAXN];

void getmx(char *s, int n)
{
    int now = 1;
    while (now <= n)
    {
        if (!mx[now])
            mx[now] = now;
        int j = now, k = now + 1;
        while (k <= n && s[j] >= s[k])
        {
            if (!mx[k])
                mx[k] = now;
            if (s[j] == s[k])
                j++;
            else
                j = now;
            k++;
        }
        while (now <= j)
            now += k - j;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    getmx(s, n);
    for (int i = 1; i <= n; i++)
        cout << mx[i] << " " << i << endl;
    return 0;
}