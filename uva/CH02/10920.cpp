#include <iostream>
#include <cmath>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
int main()
{
    long long int N, k,n,line, col, rel,tmp;
    while (true)
    {
        scanf("%lld %lld", &N, &k);
        if (N == 0 && k == 0)
            break;
        n = ceil(sqrt(k)); if(n%2 == 0) n++;
        rel = k - ((n-2) * (n-2));
        if (n == 1)
        {
            line = 1; col = 1;
        }
        else
        {
            tmp = rel/(n-1);
            if (tmp == 0)
            {
                line = n;
                col = n - rel;
            }
            else if (tmp == 1)
            {
                line = 2 * n - 1 - rel;
                col = 1;
            }
            else if (tmp == 2)
            {
                line = 1;
                col = rel - (2*n - 3);
            }
            else
            {
                line = rel - (3*n - 4);
                col = n;
            }
        }
        line += (N - n)/2;
        col += (N - n)/2;
        cout << "Line = " << line << ", column = " << col << ".\n";
    }
}