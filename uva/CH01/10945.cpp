#include <iostream>
#include <cctype>
#define FOR(i,j,n) for (int i = j; i < n; i++)
using namespace std;
int main() {
	string s;
	getline(cin,s);
	int i, j;
	while (s!="DONE") {
		i = 0;
		j = s.length() - 1;
		while (i < j) {
			while (!(s[i] - 'a' >= 0 && s[i] - 'z' <= 0) && !(s[i] - 'A' >= 0 && s[i] - 'Z' <= 0)) {
				i++;
			}
			while (!(s[j] - 'a' >= 0 && s[j] - 'z' <= 0) && !(s[j] - 'A' >= 0 && s[j] - 'Z' <= 0)) {
				j--;
			}
			if (tolower(s[i]) != tolower(s[j]))break;
			i++; j--;
		}
		if(i>=j) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
		getline(cin,s);
	}
}