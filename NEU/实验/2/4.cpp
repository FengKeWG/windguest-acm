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
#define ls (r << 1)
#define rs (r << 1 | 1)
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

void transMat(int **mat, int **res, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            *(*(res + j) + i) = *(*(mat + i) + j);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int **a = new int *[3];
    for (int i = 0; i < 3; i++)
        a[i] = new int[3];
    int **b = new int *[3];
    for (int i = 0; i < 3; i++)
        b[i] = new int[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> *(*(a + i) + j);
    transMat(a, b, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << *(*(b + i) + j) << " ";
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
        delete[] a[i];
    delete[] a;
    for (int i = 0; i < 3; i++)
        delete[] b[i];
    delete[] b;
    return 0;
}