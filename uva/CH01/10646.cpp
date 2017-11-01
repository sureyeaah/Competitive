#include <iostream>
using namespace std;
int main() {
	int t, x, y, tc, ac;
	char c, cs[52], cv[52];
	cin >> t;
	for(int j = 0; j < t; j++) {
		for(int i = 0; i < 52; i++) {
			cin >> cv[51-i] >> cs[51-i];
		}
		y = 0;
		tc = 25;
		for(int i = 0; i < 3; i++) {
			c = cv[tc];
			if(c >= '2' && c <= '9')
				x = c - '0';
			else x = 10;
			y += x;
			tc += 11 - x;
		}
		if(51 - tc >= y)
			ac = 52 - y;
		else ac = 77 - tc - y;
		cout << "Case " << j + 1 << ": " << cv[ac] << cs[ac] << endl;
	}
}