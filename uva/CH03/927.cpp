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
    int c, degree, polynomial[21], d, k;
    scanf("%d", &c);
    while(c--) {
        scanf("%d", &degree);
        FOR0(i, degree+1) scanf("%d", polynomial+i);
        scanf("%d%d", &d, &k);
        int index = ceil((double)k / (double)d);
        // n^2 + n = 2*index
        int n = ceil((-1 + sqrt(1+(8*index)))/((double)2));
        ll a = 0;
        FOR0(i, degree+1) {
            a += (ll)polynomial[i]*pow(n, i);
        }
        printf("%lld\n", a);
    }
}