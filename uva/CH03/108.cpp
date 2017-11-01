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

int main() {
    int maxSum = -127*100*100, n, sum[100][100][100] = {}; // [row][colStart][colEnd]
    scanf("%d", &n);
    // get input
    FOR0(i, n) {
        FOR0(j, n) { 
            scanf("%d", &sum[i][j][j]);
        }
    }
    // dp table for each row, O(n^3)
    FOR0(i, n) {
        FOR0(start, n) {
            FOR(end, start+1, n) {
                sum[i][start][end] = sum[i][start][end-1] + sum[i][end][end];
            }
        }        
    }
    // solve in O(n^3)
    FOR0(start, n) {
        FOR(end, start, n) {
            int currSum = 0;
            FOR0(i,n) {
                currSum += sum[i][start][end];
                maxSum = MAX(maxSum, currSum);
                if(currSum < 0) currSum = 0;
            }
        }
    }
    cout << maxSum << endl;
}