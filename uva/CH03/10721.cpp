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

int main() {
    int n,k,m;
    ll bc[52][52][52] = {}; // choose[n-1][k-1] = bc[n][k][n]
    FOR(i,1,51) bc[i][1][i] = 1;
    FOR(a,2,51) {
        FOR(b,2,a+1) {
            bc[a][b][a] = bc[a-1][b][a-1] + bc[a-1][b-1][a-1];
        }
    }
    int max_n = 0;
    while(cin >> n) {
        cin >> k >> m;
        m = MIN(n,m);
        FOR(a,max_n+1,n+1) {
             FOR(c,1,a+1) {
                 FOR(b,a/c,a) {
                    if(b*c == a) {
                        bc[a][c][b] = 1;
                    } else {
                        bc[a][c][b] = bc[a][c][b-1];
                        int r = 1;
                        while(r <= c && (a > b*r)) {
                            bc[a][c][b] += bc[a-(b*r)][c-r][MIN(b-1,a-(b*r))]*bc[c+1][r+1][c+1];
                            r++;
                        }
                    }
                }
            }
        }
        max_n = MAX(max_n, n);
        printf("%lld\n",bc[n][k][m]);
    }
}