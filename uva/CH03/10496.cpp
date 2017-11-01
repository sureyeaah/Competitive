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
typedef vector<vi> vvi;

int X, Y, beeper[11][2], cases, dist[11][11], dp[11][2048], n;

int tsp(int pos, int mask) {
    if(mask == ((1 << n) - 1))
        return dist[0][pos];
    if(dp[pos][mask] != -1)
        return dp[pos][mask];
    int least = INF;
    FOR0(i, n) {
        if(i != pos && !(mask & (1 << i))) {
            least = MIN(least, dist[pos][i] + tsp(i, mask | (1 << i)));
        }
    }
    return dp[pos][mask] = least;
}

int main() {
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d%d", &X, &Y);
        scanf("%d%d", &beeper[0][0], &beeper[0][1]);
        scanf("%d", &n);
        FOR0(i, n) scanf("%d%d", &beeper[i+1][0], &beeper[i+1][1]);
        n++;
        FOR0(i, n) {
            FOR0(j, i) {
                dist[i][j] = dist[j][i] = ABS(beeper[i][0] - beeper[j][0]) + ABS(beeper[i][1] - beeper[j][1]);
            }
        }
        FOR0(i, n) {
            FOR0(j, 2048) {
                dp[i][j] = -1;
            }
        }
        cout << "The shortest path has length " << tsp(0, 1) << endl;
    }
}
