#include <iostream>
#include <map>
using namespace std;
int main() {
	map <char, char> w;
	w['A'] = 'A';
	w['E'] = '3';
	w['H'] = 'H';
	w['I'] = 'I';
	w['J'] = 'L';
	w['L'] = 'J';
	w['M'] = 'M';
	w['O'] = 'O';
	w['S'] = '2';
	w['T'] = 'T';
	w['U'] = 'U';
	w['V'] = 'V';
	w['W'] = 'W';
	w['X'] = 'X';
	w['Y'] = 'Y';
	w['Z'] = '5';
	w['1'] = '1';
	w['2'] = 'S';
	w['3'] = 'E';
	w['5'] = 'Z';
	w['8'] = '8';
	string s;
	bool p, m;
	while (cin >> s) {
		p = m = true;
		int l = s.length();
		if (l % 2 == 1 && w[s[l / 2]] != s[l / 2]) {
			m = false;
		}
		for (int i = 0; i < l / 2; i++) {
			if (w[s[i]] != s[l - i - 1]) m = false;
			if (s[i] != s[l - i - 1]) p = false;
		}
		cout << s;
		if (p) {
			if (m) cout << " -- is a mirrored palindrome." << endl << endl;
			else cout << " -- is a regular palindrome." << endl << endl;
		} else {
			if (m) cout << " -- is a mirrored string." << endl << endl;
			else cout << " -- is not a palindrome." << endl << endl;
		}
	}
}