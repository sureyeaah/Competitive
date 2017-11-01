#include <algorithm>
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
int n, m, vessel[1001];
bool check(int x) {
	int curr = 0;
	FOR0(i, m) {
		int filled = 0;
		while(curr < n && filled+vessel[curr] <= x) filled += vessel[curr++];
		if(curr == n) return true;
	}
	return false;
}
int main() {    
    while(scanf("%d%d", &n, &m)!=EOF) {
		m = MIN(n,m);
		FOR0(i,n) scanf("%d", vessel+i);
		int l = 1, r = 1000000*n + 1, mid;
		while (l < r) {
			mid = (l+r)/2;
			if(check(mid)) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("%d\n",l);
    }
}