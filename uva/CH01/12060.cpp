#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y);
}
int numDig(int x) {
	if(x<100) {
		if(x>9){ 
			return 2;
		}
		if(x) return 1;
		return 0;
	}
	if(x < 1000) return 3;
	if(x < 10000) return 4;
	return 5;
}
int main() {
	ios::sync_with_stdio(false);
	int cs=0, n, x, a, b, c ;
	while(true) {
		bool neg = false;
		cin >> n;
		if(n==0) break;
		cs++;
		int sum = 0;
		FOR0(i,n) {
			cin >> x;
			sum += x;
		}
		if(sum < 0) {neg = true; sum = -sum;}
		a = sum/n;
		b = sum - a*n;
		c = n;
		cout << "Case " << cs << ":" << endl;
		if(b == 0) {
			if(neg) cout << "- ";
			cout << a << endl; 
		} else {
			int div = gcd(c,b);
			c /= div; b /= div;
			int da = numDig(a) + (neg ? 2 : 0);int db = numDig(b); int dc = numDig(c);
			FOR0(i,da+dc-db) cout << ' ';
			cout << b << endl;
			if(neg) cout << "- ";
			if(a) cout << a;
			FOR0(i,dc) cout << '-';
			cout << endl;
			FOR0(i,da) cout << ' ';
			cout << c << endl;
		}
	}
}