#include <iostream>
#include <vector>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int main(){
    // ios_base::sync_with_stdio(0);
    int n, x, array[1000];
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        bool allzero = true, started = false;
        int startsAt = 0;
        // get input.
        FOR0(i, n) {
            scanf("%d", array+i);
            if(array[i] && allzero) {
                allzero = false;
                startsAt = i;
            } 
        }
        // greedy
        if(allzero) cout << 0 << endl;
        else {
            printf("%d", array[startsAt]);
            startsAt++;
            FOR(i, startsAt, n) {
                if(array[i]) printf(" %d", array[i]);
            }
            printf("\n");
        }
    }
    return 0;
}