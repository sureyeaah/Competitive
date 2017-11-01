#include <iostream>
#include <algorithm>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;

int main() {
	//ios::sync_with_stdio(false);
	int r;
	cin >> r;
	char c;
	while (r != -1) {
		int wg = 0, gl = 0, wl=0, cg=0; bool w[26] = {}, gb[26] = {}; char g[26];
		c = getchar();
		while(c = getchar(), c!='\n') {
			w[c-'a'] = true;
		}
		FOR0(i,26) {
			if(w[i]) wl++;
		}
		while(c=getchar(), c!='\n') {
			if(!gb[c-'a']) {
				g[gl] = c;
				gb[c-'a'] = true;
				gl++;
			}
		}
		cout << "Round " << r << endl;
		FOR0(i,gl) {
			if(!w[g[i]-'a']) {
				wg++;
				if(wg == 7) {
					cout << "You lose." << endl;
					break;
				}
			} else {
					cg++;
					if(cg==wl) {
						cout << "You win." << endl;
						break;
					}
				}
		}
		if(cg<wl && wg!=7) cout << "You chickened out." << endl;
		cin >> r;
	}
}