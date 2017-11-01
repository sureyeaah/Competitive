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
struct stone {
    bool big;
    int distance;
} ;
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int main(){
    //ios_base::sync_with_stdio(0);
    int t, n, d, x;
    stone stones[102];
    char size;
    scanf("%d", &t);
    FOR0(tc, t) {
        int maxLeap = 0, numBig = 0, numSmall = 0;
        scanf("%d%d\n", &n, &d);
        stones[0] = {true, 0};
        FOR(i,1,n+1) {
            scanf("%c-%d", &size, &x);
            if(size == 'B')
                stones[i] = {true, x};
            else
            stones[i] = {false, x};
            cin.ignore();
        }
        stones[n+1] = {true, d};
        int i = 0;
        while(i < n+1) {
            int nextBig = i+1;
            while(!stones[nextBig].big) nextBig++;
            if(nextBig == i+1) {
                maxLeap = MAX(stones[i+1].distance - stones[i].distance, maxLeap);
            }
            else {
                FOR(j, i+2, nextBig+1) {
                    maxLeap = MAX(stones[j].distance - stones[j-2].distance, maxLeap);
                }
            }
            i = nextBig;
        }
        
        printf("Case %d: %d\n", tc+1, maxLeap); 
    }
    return 0;
}