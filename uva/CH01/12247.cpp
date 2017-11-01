#include <iostream>
#include <algorithm>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int c[] = {0,3,3,2,0};
int main() {
	ios::sync_with_stdio(false);
	int a[5], x[2], ans;
	a[0] = 0; a[4] = 53;
	while (true) {
		cin >> a[1] >> a[2] >> a[3] >> x[0] >> x[1];
		if (a[1] == 0) break;
		ans = 0;
		sort(a+1, a+4);
		sort(x,x+2);
		int i1 = lower_bound(a,a+5,x[1]) - a;
		int i2 = lower_bound(a,a+5,x[0]) - a;
		if(i1 == 1 || i1 == 2) { //part 1
			cout << "-1" << endl;
		} else if(i1 == 3) { //part 2
			if(i2 == 1 || i2 == 2) {
				cout << "-1" << endl;
			} else {
				FOR(i,a[2]+1,a[3]) {
					if(i!=x[0] && i!=x[1]) {ans = i; break;}
				}
				if(ans){cout << ans << endl;}
				else {
					FOR(i,a[3]+1,53) {
						if(i!=x[0] && i!=x[1]) {ans = i; break;}
					}
					if(ans){cout << ans << endl;}
					else {cout << "-1" << endl;}	
				}
			}
		} else {
			FOR(i,a[c[i2]]+1,53) {
				if(i!=x[0] && i!=x[1] && i!=a[1] &&i!=a[2]&&i!=a[3]) {ans = i; break;}
			}
			if(!ans) cout << "-1" << endl;
			else cout << ans << endl;
		}
	}
}