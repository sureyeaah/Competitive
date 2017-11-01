#include <iostream>
#include <vector>
#include <algorithm>
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int n, q, d, m, dp[15][25], input[210]; // dp[ch][rem]
    for(int setNumber = 1;;setNumber++) {
        scanf("%d%d", &n, &q);
        if(n == 0 && q==0) break;
        FOR0(i, n) scanf("%d", input+i);
        printf("SET %d:\n", setNumber);
        FOR(queryNumber, 1, q+1) {
            scanf("%d%d", &d, &m);
            FOR0(i, m+1) {FOR0(j, d) {dp[i][j] = 0;}} // reset dp table
            // core code
            if(m <= n) {
                FOR0(i, n) {
                    int curr_rem = ((input[i]%d)+d)%d;
                    FORD(ch,MIN(i+1, m),2) {
                        FOR0(rem, d) {
                            dp[ch][(rem+curr_rem)%d] += dp[ch-1][rem];
                        }
                    }
                    dp[1][curr_rem]++;
                }
            }
            // output
            printf("QUERY %d: %d\n", queryNumber, dp[m][0]);
        }
    }
}