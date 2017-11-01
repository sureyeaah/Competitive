#include <iostream>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
int main()
{
    string s1, s2;
    int n, cases=0;
    long long int start, prev, x;
    while (cin >> n, n)
    {
        cases++;
        cout << "Case " << cases << ":" << endl;
        cin >> x;
        start = x;
        prev = start;
        n--;
        bool consec = false;
        while (n--)
        {
            cin >> x;
            while (x - prev == 1)
            {
                consec = true;
                prev++;
                if (!n)
                    break;
                cin >> x;
                n--;
            }
            if (prev == start)
            {
                consec = false;
                cout << "0" << start << endl;
                start = prev = x;
            }
            else
            {
                cout << "0";
                s1 = to_string(start);
                s2 = to_string(prev);
                int i = 0, l = s1.length();
                for(; i < l; i++) {
                    if(s1[i] != s2[i]) break;    
                }
                cout << start<< "-";
                for(; i < l; i++) {
                    cout << s2[i] ;
                }
                cout << endl;
                if(x!=prev) consec = false;
                start = prev = x;
            }
        }
        if(!consec) cout << "0" << x << endl;
        cout << endl;
    }
}