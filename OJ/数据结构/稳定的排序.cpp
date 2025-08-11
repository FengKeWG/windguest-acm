#include <bits/stdc++.h>
#define int long long
// #define int unsigned long long
// #define int __int128
#define endl '\n'
#define N 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define mid ((t[r].l + t[r].r) >> 1)
#define lson (r << 1)
#define rson (r << 1 | 1)
using namespace std;

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

int n;
vector<string> a, b, c;
bool bub, sel;
vector<char> A[10], B[10], C[10];

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    a.resize(n), b.resize(n), c.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = b[i] = a[i];
        A[a[i][1] - '0'].push_back(a[i][0]);
    }
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (b[j - 1][1] > b[j][1])
                swap(b[j], b[j - 1]);
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
        B[b[i][1] - '0'].push_back(b[i][0]);
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < B[i].size(); j++)
        {
            if (A[i][j] != B[i][j])
            {
                bub = 1;
                break;
            }
        }
        if (bub)
            break;
    }
    cout << endl;
    if (bub)
        cout << "Not stable" << endl;
    else
        cout << "Stable" << endl;
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (c[j][1] < c[k][1])
                k = j;
        }
        swap(c[i], c[k]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
        C[c[i][1] - '0'].push_back(c[i][0]);
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < C[i].size(); j++)
        {
            if (A[i][j] != C[i][j])
            {
                sel = 1;
                break;
            }
        }
        if (sel)
            break;
    }
    cout << endl;
    if (sel)
        cout << "Not stable" << endl;
    else
        cout << "Stable" << endl;
    return 0;
}