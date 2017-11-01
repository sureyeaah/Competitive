#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, d, r, morning[100], evening[100];
    while(true) {
        ll cost = 0;
        scanf("%d%d%d", &n, &d, &r);
        if(n==0 && d==0 && r==0) break;
        FOR0(i, n) scanf("%d", morning+i);
        FOR0(i, n) scanf("%d", evening+i);
        // sort the route lengths
        sort(morning, morning+n);
        sort(evening, evening+n);
        FOR0(i, n) {
            int over = morning[i] + evening[n - i - 1] - d;
            if(over > 0) cost += over*r;
        }
        printf("%lld\n", cost);
    }
    return 0;
}