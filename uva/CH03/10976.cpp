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
    int x_out[10000], y_out[10000], k;
    double x;
    while(cin >> k) {
        int num = 0;
        FOR(y,k+1,2*k+1) {
            x = (double)(k*y)/((double)(y-k));
            if(x == ((int)x)) {
                y_out[num] = y;
                x_out[num] = (int)x;
                num++;
            }
        }
        printf("%d\n", num);
        FOR0(i, num) printf("1/%d = 1/%d + 1/%d\n", k,x_out[i],y_out[i]);
    }
}