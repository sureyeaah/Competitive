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

int numWays[2][6010] = {}, LastCalc = 0, n;
long long int m[6010];
// if using the 5 coin only, 1 way only for n >= 5
// if using the 5 & 10 coin, ways are floor(n/10) + 1
// numWays[0] ways when using 5,10,25 coins
// numWays[1] ways for using 5,10,25,50 coins
// we divide all values of coins as well the n by 5 becauses ways(5n+r) equal for all positive r < 5

int main() {
    m[0] = 1;
    while(cin >> n) {
        int byFive = n/5;
        numWays[0][0] = numWays[1][0] = 1;
        FOR(j, LastCalc+1, byFive+1) {
            numWays[0][j] = (j >= 5) ? ((int)(j/2) + 1 + numWays[0][j-5]) : ((int)(j/2) + 1);
        }
        FOR(j, LastCalc+1, byFive+1) {
            numWays[1][j] = (j >= 10) ? (numWays[0][j] + numWays[1][j-10]) : numWays[0][j];
        }
        FOR(j,LastCalc+1,byFive+1) m[j] = m[j-1] + numWays[1][j];
        if(m[byFive] > 1)
            printf("There are %lld ways to produce %d cents change.\n", m[byFive], n);
        else
            printf("There is only 1 way to produce %d cents change.\n", n);
        LastCalc = MAX(LastCalc, byFive);
    }
}