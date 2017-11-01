#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
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

int n, coords[8][2], sequence[10];
double dist[8][8], dp[8][260];

double tsp(int pos, int mask) {
    if(dp[pos][mask] != -1)
        return dp[pos][mask];
    double ret = INF;
    FOR0(i, n) {
        if(i != pos && (mask & (1 << i)))
            ret = MIN(ret, dist[pos][i] + tsp(i, mask & ~(1<<i)));
    }
    return dp[pos][mask] = ret;
}

void reconstruct(int k, int mask) {
    if(k==n) return;
    double least = INF;
    FOR0(i, n) {
        double val = dp[i][mask & ~(1 << i)];
        if((mask & (1 << i)) && val < least) {
            least = val;
            sequence[k] = i;
        }
    }
    reconstruct(k+1, (mask & ~(1 << sequence[k])));
}

int main() {
    int casenumber = 0;
    while(++casenumber) {
        scanf("%d", &n);
        if(n == 0) break;
        // compute distances
        FOR0(i, n) scanf("%d%d", &coords[i][0], &coords[i][1]);
        FOR0(i, n) {
            dist[i][i] = 0;
            FOR0(j, i) {
                dist[i][j] = dist[j][i] = 16.0 + sqrt((double)pow(coords[i][0] - coords[j][0], 2) + (double)pow(coords[i][1] - coords[j][1], 2));
            }
        }
        FOR0(i, n) { FOR0(j, 260) { dp[i][j] = -1;} dp[i][0] = 0;} // reset dp table
        //tsp
        double least = INF;
        FOR0(i, n) least = MIN(least, tsp(i, (((1 << n)-1) & ~(1 << i))));
        reconstruct(0, (1 << n) - 1);
        printf("**********************************************************\nNetwork #%d\n", casenumber);
        FORD(i,n-1,1) {
            int a = sequence[i], b = sequence[i-1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", coords[a][0], coords[a][1], coords[b][0], coords[b][1],dist[a][b]);
        }
        printf("Number of feet of cable required is %.2f.\n", least);
    }
}