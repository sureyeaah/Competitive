#include <iostream>
using namespace std;
int main() {
	//ios::sync_with_stdio(false);
	int t, l; char c; string s;
	scanf("%d", &t);
	getline(cin, s);
	while (t--) {
		int w[12] = {};
		for (int i = 0; i < 3; i++) {
			getline(cin, s);
			l = s.find(" ");
			if (s[2*l + 2] == 'e') {
				for (int j = 0; j < l; j++) {
					w[s[j] - 'A'] = 1;
				}
				for (int j = l + 1; j < 2*l + 1; j++) {
					w[s[j] - 'A'] = 1;
				}
			}
			else {
				int type = s[2*l + 2] == 'd' ? 0 : 1;
				for (int j = 0; j < l; j++) {
					c = s[j];
					if (w[c - 'A'] != 1) {
						w[c - 'A'] = w[c - 'A'] == 2 + type ? 1 : 3 - type;
					}
				}
				for (int j = l + 1; j < 2*l + 1; j++) {
					c = s[j];
					if (w[c - 'A'] != 1) {
						w[c - 'A'] = w[c - 'A'] == 3 - type ? 1 : 2 + type;
					}
				}
				if(i){
					for(int j = 0; j < 12; j++) {
						if(w[j] > 1 && s.find((char)('A'+j)) > 2*l) {
							w[j] = 1;
						}
					}
				}
			}
		}
		for (int i = 0; i < 12; i++) {
			if (w[i] == 3) {
				cout << (char)('A' + i) << " is the counterfeit coin and it is light." << endl;
				break;
			}
			else if (w[i] == 2) {
				cout << (char)('A' + i) << " is the counterfeit coin and it is heavy." << endl;
				break;
			}
		}
	}
}