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

#define MOD 1000000;
int main() {
    int n, k, choose[201][101] = {}, a_max = 0;
    while(true) {
        scanf("%d%d", &n , &k);
        if(n == 0 && k == 0) break;
        FOR0(i,101) choose[i][0] = 1;
        FOR(a,a_max+1,n+k) {
            FOR(b,1,a+1) {
                choose[a][b] = (choose[a-1][b-1] + choose[a-1][b])%MOD;
            }
        }
        printf("%d\n", choose[n+k-1][k-1]);
        a_max = MAX(a_max, n+k - 1);
    }
}