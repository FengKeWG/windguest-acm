#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200005
#define M 100005
#define MOD 1000000007
#define eps 1e-6
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// #define mid ((t[r].l + t[r].r) >> 1)
// #define ls (r << 1)
// #define rs (r << 1 | 1)
using namespace std;

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

class ArrayOfInt
{
private:
    int asize;
    int *p;

public:
    ArrayOfInt() : asize(10)
    {
        p = new int[asize];
        for (int i = 0; i < asize; i++)
            p[i] = 0;
    }
    ArrayOfInt(const ArrayOfInt &t) : asize(t.asize)
    {
        p = new int[asize];
        for (int i = 0; i < asize; i++)
            p[i] = t.p[i];
    }
    ~ArrayOfInt()
    {
        delete[] p;
    }
    int &operator[](int index)
    {
        return p[index];
    }
    const int &operator[](int index) const
    {
        return p[index];
    }
    ArrayOfInt &operator=(const ArrayOfInt &t)
    {
        if (this == &t)
        {
            return *this;
        }
        if (asize != t.asize)
        {
            delete[] p;
            asize = t.asize;
            p = new int[asize];
        }
        for (int i = 0; i < asize; ++i)
        {
            p[i] = t.p[i];
        }

        return *this;
    }
    int size() const
    {
        return asize;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    return 0;
}