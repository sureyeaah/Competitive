#include <iostream>
#include <bitset>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
short int getsi()
{
    char c;
    short int ret = 0;
    bool start = false;
    while (true)
    {
        c = getchar();
        if (c == EOF)
            break;
        if ((c - '0' < 0 || c - '0' > 9) && !start)
        {
            continue;
        }
        if ((c - '0' < 0 || c - '0' > 9) && start)
        {
            break;
        }
        if (start)
            ret *= 10;
        start = true;
        ret += c - '0';
    }
    return ret;
}
using namespace std;
int main()
{
    short int cor[16384],pot[16384], pow2[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
    while (true)
    {
        int n = getsi();
        if (n == 0)
            break;
        int maxpot = 0, up = pow2[n];
        FOR0(i, up)
        {
            cor[i] = getsi();
        }
        FOR0(i, up)
        {
            pot[i] = 0;
            FOR0(x, n)
            {
                pot[i] += cor[i ^ (1 << x)];
            }
        }
        FOR0(i,up) {
            FOR0(x,n) {
                maxpot = MAX(maxpot, pot[i] + pot[i^(1<<x)]);
            }
        }
        cout << maxpot << endl;
    }
}

/*


*/