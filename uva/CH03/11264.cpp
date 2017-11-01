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
    int tc, n, x, prevx;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        // greedy
        scanf("%d", &prevx);
        long long int sum = prevx; 
        int totalCoins = 1;
        n--;
        while(n--) {
            scanf("%d", &x);
            if(sum < x) {
                sum += x;
                totalCoins++;    
            } else {
                sum += x - prevx;
            }
            prevx = x;
        }
        printf("%d\n", totalCoins);
    }
    return 0;
}