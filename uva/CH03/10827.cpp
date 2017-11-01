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
    int testcases, n, sum[75][75][75]; // [row][colStart][colEnd]
    cin >> testcases;
    while(testcases--) {
        scanf("%d", &n);
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
                FOR(end, 0, start) {
                    sum[i][start][end] = sum[i][start][n-1] + sum[i][0][end];
                }
            }        
        }
        int maxSum = -100*n*n;
        FOR0(start, n) {
            FOR0(end, n) {
                int currSum = 0, totalSum = 0;
                bool neg = false, pos = false;
                FOR0(i,n) {
                    int curr = sum[i][start][end];
                    if (curr < 0) neg = true;
                    else pos = true;
                    currSum += curr; totalSum += curr;
                    maxSum = MAX(maxSum, currSum);
                    if(currSum < 0) currSum = 0;
                }
                if(neg && pos) {
                    int minSum = -100*n*n;
                    currSum = 0;
                    FOR0(i,n) {
                        currSum -= sum[i][start][end];
                        minSum = MAX(minSum, currSum);
                        if(currSum < 0) currSum = 0;
                    }
                    maxSum =  MAX(maxSum, totalSum + minSum);
                }
            }
        }
        cout << maxSum << endl;
    }
    
}