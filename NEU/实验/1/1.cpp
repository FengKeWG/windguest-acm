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

inline void print(int x)
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

enum CPU_Rank
{
    P1 = 1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7
};

class CPU
{
private:
    CPU_Rank rank;
    int frequency;
    double voltage;

public:
    CPU(CPU_Rank r, int f, double v) : rank(r), frequency(f), voltage(v)
    {
        cout << "Construct CPU" << endl;
    }

    ~CPU()
    {
        cout << "Destruct CPU" << endl;
    }

    void Run()
    {
        cout << "CPU run" << endl;
    }

    void Stop()
    {
        cout << "CPU stop" << endl;
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    CPU a(P6, 300, 2.8);
    a.Run();
    a.Stop();
    return 0;
}