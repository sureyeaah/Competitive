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
int main(){
    long long int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &n, &m);
        long long distance = n*m/2;
        printf("%lld\n", distance);
    }
    return 0;
}

/*
for(int i = 1; i <= n/m; i+= 2) {
            distance += m*m;
        }
distance += m*((2*i - 1) * m + 1)/2;
            distance -= m
*/