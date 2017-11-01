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

int main() {
    int t,n,m,k,p[101][101], rowSum[101][101][101];
    cin >> t;
    FOR(casenumber,1,t+1) {
        scanf("%d%d", &n, &m, &k);
        FOR0(i, n) {
            FOR0(j, m) {
                scanf("%d", &p[i][j]);
            }
        }
        int maxSize = 0, bestPrice = INF;
        FOR0(row, n) {
            FOR0(start, m) {
                rowSum[row][start][start] = p[row][start];
                FOR(end, start+1, m) {
                    rowSum[row][start][end] = rowSum[row][start][end-1] + p[row][end];
                }
            }
        }
        FOR0(start, m) {
            FOR(end, start, m) {
                FOR(rowStart, 0, n) {
                    FOR(rowEnd, rowStart, n) {
                         
                    }
                }
            }
        }
    }
}