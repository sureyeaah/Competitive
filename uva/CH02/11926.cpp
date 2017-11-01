#include <iostream>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
// int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main()
{
    int n, m, a, b, c;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        bool cal[1000100] = {false}, conflict = false;

        while (n--)
        {
            cin >> a >> b;
            if (!conflict)
            {
                FOR(t, a, b)
                {
                    if (cal[t])
                        {conflict = true; break;}
                    cal[t] = true;
                }
            }
        }

        while (m--)
        {
            cin >> a >> b >> c;
            while (!conflict && a < 1000000)
            {
                FOR(t, a, b)
                {
                    if (cal[t])
                    {
                        conflict = true;
                        break;
                    }
                    cal[t] = true;
                }
                a += c;
                b = MIN(b + c, 1000000);
            }
        }
        if (conflict)
            cout << "CONFLICT" << endl;
        else
            cout << "NO CONFLICT" << endl;
    }
}