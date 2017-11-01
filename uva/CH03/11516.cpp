#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
    int x, z, n, a, b, c;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d", &a, &b, &c);
        if((double)c >= 3*pow((double)b,2.0/3.0)) {
                for(x = -100; x < 22; x++) {
                    for(int y = x+1, last_y = ((x <= 0) ? 0: 100); y < last_y; y++) {
                        z = a - x - y;
                        if(z!=x && y!=z && x*y*z == b && (x*x + y*y + z*z) == c) {
                            printf("%d %d %d\n",x,y,z);
                            x = y = INF;
                        }
                    }
                }
        }
        if(x < INF) printf("No solution.\n");
    }
}