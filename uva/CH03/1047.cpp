#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
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
    int n, numTowers, customers[21], m, t, x;
    map<int, int> common;
    while(true) {
        scanf("%d%d" &n, &numTowers);
        FOR0(i, n) scanf("%d", customers+i);
        scanf("%d", &m);
        FOR0(i, m) {
            scanf("%d", &t);
            int bitmask = 0;
            FOR0(i, t) {
                scanf("%d", &x);
                bitmask |= (1 << x); 
            }
            scanf("%d", &x);
            common[bitmask] = x; 
        }
        
    }
}