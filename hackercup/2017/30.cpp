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
    int t, n, w[100];
    scanf("%d", &t);
    FOR(day, 1, t+1) {
        scanf("%d", &n);
        FOR0(i, n) scanf("%d", w+i);
        sort(w, w+n, greater<int>());
        int sum = 0, trips = 0;
        FOR0(i, n) {
            sum += w[i];
            while(sum < 50 && i != n-1) {
                sum += w[i];
                n--;
            }   
            if(sum >= 50) {
                sum = 0;
                trips++;
            }
        }
        printf("Case #%d: %d\n", day, trips);
    }
}