#include <iostream>
#include <set>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int n, k, x;
    while(true) {
        multiset<int> urn;
        multiset<int>::iterator first, last;
        long long int cost = 0;
        n = geti();
        if(!n) break;
        while(n--) {
            k = geti();
            while(k--) {
                x = geti();
                urn.insert(x);
            }
            first = urn.begin(); last = prev(urn.end());
            cost += (*last) - (*first);
            urn.erase(first); urn.erase(last);
        }
        cout << cost << endl;
    }

}