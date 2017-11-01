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
    int k, s[12];
    bool started = false;
    while(true) {
        scanf("%d", &k);
        if(k == 0) break;
        if(started) printf("\n");
        FOR0(i, k) scanf("%d", s+i);
        sort(s, s+k);
        FOR(a, 0, k - 5) {
            FOR(b, a+1, k - 4) {
                FOR(c, b+1, k - 3) {
                    FOR(d, c+1, k - 2) {
                        FOR(e, d+1, k - 1) {
                            FOR(f, e+1, k) {
                                printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
                            }
                        }
                    }
                }
            }
        }
        started = true;
    }
}