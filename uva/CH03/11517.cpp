#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 1000000000
#define LAST 20000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int tc, price, n, coins[101], dp[LAST];
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &price, &n);
        FOR0(i,n) scanf("%d", coins+i);
        dp[0] = 0;
        FOR(i,1,LAST) dp[i] = INF;
        FOR0(j, n) {
             FORD(i,LAST-coins[j],0) {
                if(dp[i] < INF) dp[i+coins[j]] = MIN(dp[i]+1, dp[i+coins[j]]);
            }
        }
        FOR(i,price,LAST) {
            if(dp[i] < INF) {
                printf("%d %d\n", i, dp[i]);
                break;
            }
        }
    }
}