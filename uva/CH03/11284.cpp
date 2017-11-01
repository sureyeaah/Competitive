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
    int T,n,m,p,road[1010][2],store[12];
    double fuel[1010], diff[12], cheapest[15][15];

    scanf("%d", &T);
    while(T--) {
        // input
        scanf("%d%d", &n, &m);
        FOR0(i, m) scanf("%d%d%f", &road[i][0], &road[i][1], &fuel[i]);
        scanf("%d", &p);
        FOR0(i, p) scanf("%d %f", &store[i], &diff[i]);
        // find cheapest ways to move from store to store
        
    }
}