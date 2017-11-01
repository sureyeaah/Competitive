#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int main() {
	//ios::sync_with_stdio(false);
	int m, n;
	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		if (MIN(m, n) < 2) {
			cout << m*n;
		}
		else if(MIN(m,n) == 2) {
			int k = MAX(m,n);
			if(k%4 == 0) cout << k;
			else if(k%2 == 0) cout << k+2;
			else cout << k+1;
		}
		else if (MAX(m, n) == 3) {
			cout << m + n - 1;
		}
		else {
			cout << (m * n + 1) / 2;
		}
		cout << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	}
}