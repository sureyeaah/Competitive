#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int main() {
	//ios::sync_with_stdio(false);
	int t,m,n; char p;
	cin >> t;
	while(t--) {
		do {
			cin >> p;
		} while (p == '\n' || p == ' ');
		cin >> m >> n;
		if(p == 'r' || p=='Q')
			cout << MIN(m,n) << endl;
		else if(p=='K')
			cout << (int)((m+1)/2) * (int)((n+1)/2) << endl;
		else {
			cout << (int)(m*n + 1)/2 << endl;
		}
	}
}