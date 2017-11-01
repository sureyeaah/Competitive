#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int main() {
	//ios::sync_with_stdio(false);
	int l;
	char c[2];
	while(true) {
		int dir = 0;
		int sign= 1;
		cin >> l;
		c[0] = getchar();
		if(l == 0) break;
		FOR0(i,l-1) {
			c[0]=getchar();c[1]=getchar();
			if(c[0] != 'N') {
				if(dir == 0) {
					dir = c[1] - 'x';
					sign *= ((c[0]=='+') ? 1 : -1);
				}
				else if(dir == c[1]-'x') {
					sign *= ((c[0]=='+') ? -1 : 1);
					dir = 0;
				}
			}
			c[0]=getchar();
		}
		if(sign==1) cout << '+'; else cout << '-';
		cout << (char)('x'+dir) << endl;
	}
}