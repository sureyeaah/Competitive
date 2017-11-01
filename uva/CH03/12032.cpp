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
#define INF 2000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// no need for binary searching the answer in this problem.
int main() {
    int T, n;
    scanf("%d", &T);
    FOR(tc, 1, T+1) {
        int x = 0, y, k = 0, curr = 0;
        bool plusOne = false;
        scanf("%d", &n);
        FOR0(i,n) {
            scanf("%d", &y);
            if(y-x > k) {
                k = y - x;
                curr = k-1;
                plusOne = false;
            } else if(!plusOne) {
                if(y-x == curr) curr--;
                else if(y-x > curr) plusOne = true;
            }
            x = y;
        }
        printf("Case %d: %d\n", tc, k+((int)plusOne));
    }
}