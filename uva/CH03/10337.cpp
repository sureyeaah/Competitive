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
// cost - 60,30,20
int main() {
    int n,x,dp[1010][11],wind[1010][11];
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        int k = x/100;
        FOR0(j,1010) dp[j][10] = INF;
        FORD(h,9,0) {
            FOR0(d, k) {
                scanf("%d",&wind[d][h]);
            }
        }
        FOR(j, 1, 12) dp[0][j] = INF;
        FOR(j,1,k+1) dp[j][0] = INF;
        FOR(d,1,k) {
             FOR(h,1,10) {
                dp[d][h] = MIN(dp[d-1][h] + 30 - wind[d-1][h], MIN(dp[d-1][h+1] + 20 - wind[d-1][h+1], dp[d-1][h-1]+60 - wind[d-1][h-1]));
                if(dp[d][h] > INF/2) dp[d][h] = INF;
            }
        }
        cout << dp[k-1][1] + 20 - wind[k-1][1] << endl << endl; 
    }
}