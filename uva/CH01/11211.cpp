#include <iostream>
#include <cctype>
#include <cmath>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
using namespace std;

int main() {
	int T; string s1;
	cin >> T;
	getline(cin,s1);
	FOR0(t, T) {
		string s2, s3;
		bool pal = true;
		getline(cin, s1);
		cout << "Case #" << t+1 << ':' << endl;
		FOR0(i, s1.length()) {
			if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
				s2.append(s1,i,1);
		}
		int l = s2.length();
		int k = sqrt(l);
		if (k * k != l) cout << "No magic :(" << endl;
		else {
			FOR0(i, l / 2) {
				if (s2[i] != s2[l - i - 1]) {
					pal = false;
					break;
				}
			}
			if (pal) {
				FOR0(i, k) {
					FOR0(j, k) {
						s3.append(s2,k * i + j,1);
					}
				}
				FOR0(i, l / 2) {
					if (s3[i] != s3[l - i - 1]) {
						pal = false;
						break;
					}
				}
			}
			if(pal) cout << k << endl;
			else cout << "No magic :(" << endl;
		}
	}
}
