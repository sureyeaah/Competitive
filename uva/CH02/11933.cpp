#include <iostream>
#include <cmath>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))

int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int n, nc;
    while(true) {
        cin >> n;
        nc = n;
        if(!n) break;
        bool take = true;
        int x = 0, index = 0;
        FOR0(i,31) {
            if(nc & 1) {
                if(take) x += pow(2,index);
                take = !take;
            }
            nc>>=1;
            index++;
        }
        cout << x << ' ' << n - x << endl;        
    }
}