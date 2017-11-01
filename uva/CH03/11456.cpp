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
    int numCases, n, input[2001], lis[2001], lds[2001];
    cin >> numCases;
    while(numCases--) {
        cin >> n;
        int maxLength = (n != 0);
        FORD(i,n-1,0) scanf("%d", input+i);
        FOR0(i,n) {
            lis[i] = 1;
            FOR0(j,i) {
                if(lis[j] >= lis[i] && input[i] > input[j]) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        FOR0(i,n) {
            lds[i] = 1;
            FOR0(j,i) {
                if(lds[j] >= lds[i] && input[i] < input[j]) {
                    lds[i] = lds[j] + 1;
                }
            }
            maxLength = MAX(maxLength, lis[i]+lds[i]-1);
        }
        cout << maxLength << endl;
    }
}