#include <iostream>
#include <set>
#include <cstring>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
using namespace std;
set<string> bg; bool a[3];

string blood[3] = {"A", "B", "O"};
void printSet(bool b) {
	if(bg.size() == 1 && !b) {cout << *bg.begin() << "-"; return;}
	if(bg.empty()) {
		cout << "IMPOSSIBLE";
	} else {
		set<string>::iterator i = bg.begin();
		cout << "{" << *i << "-";
		if(b) cout << ", " << *i << "+";
		i++;
		for(; i != bg.end(); i++) {
			cout << ", " << *i << "-";
			if(b) cout << ", " << *i << "+";
		}
		cout << "}";
	}
}
void printSet2() {
	if(bg.size() == 1) {cout << *bg.begin() << "+"; return;}
	if(bg.empty()) {
		cout << "IMPOSSIBLE";
	} else {
		set<string>::iterator i = bg.begin();
		cout << "{" << *i << "+";
		i++;
		for(; i != bg.end(); i++) {
			cout << ", " << *i << "+";
		}
		cout << "}";
	}
}
void addposs(bool O) {
	int numTrue = 0;
	FOR0(i,3) {
		if(a[i]) numTrue++;
	}
	if (numTrue == 0) {
		bg.insert("A");
		bg.insert("B");
		if(O) bg.insert("O"); else bg.insert("AB");
	}
	else if(numTrue == 1) {
		if(a[0]) {bg.insert("A"); bg.insert("AB");}
		if(a[1]) {bg.insert("B"); bg.insert("AB");}
		if(a[2]) {bg.insert("A"); bg.insert("B");}
	} else if(numTrue == 2) {
		if(a[2]) {
			if(a[0]) bg.insert("A");
			else bg.insert("B");
		} else bg.insert("AB");
	}
}
//-----------------------------------------------------------------------------------------
int main()
{
    string s[3]; int cases = 0; bool sign[2]; char c;
    while (true)
    {	
		bool b[3][3] = {false};
		bool sign[3] = {false};
		s[0] = s[1] = s[2] = "";
		FOR0(i, 3) {
			while (c = getchar(), c == ' ' || c=='\n') {continue; }
			if(c=='E') break;
			if(c == 'A') b[i][0] = true; else if(c == 'B') b[i][1] = true; else if(c == 'O') b[i][2] = true;
			s[i] += c;
			while (c = getchar(), c != ' ' && c!='\n') {
				s[i] += c;
				if(c == '+') sign[i] = true;
				else if(c == 'A') b[i][0] = true; else if(c == 'B') b[i][1] = true; else if(c == 'O') b[i][2] = true;
			}
		}

		if(c == 'E') break;
		cases++; bg.clear();
		// -------------------------------------------------------------
		if(!b[2][0] && !b[2][1] && !b[2][2]) {
			FOR0(i,3) {
				if(b[i][0] != b[i][1]) b[i][2] = true;
			}
			FOR0(i,3) {
				FOR0(j,3) {
					if(b[0][i] && b[1][j]) 
					{
						if(i == j || i == 2 || j == 2) bg.insert(blood[MIN(i,j)]);
						else bg.insert("AB");
					}
				}
			}
			cout << "Case " << cases << ": " << s[0] << ' ' << s[1] << ' ';
			printSet(sign[0] || sign[1]);
			cout << endl;
		} 
		// ------------------------------------------------------------
		else {
			int known = (!b[1][0] && !b[1][1] && !b[1][2]) ? 0 : 1;
			memset(a, false, 3);
			//----------
			if(b[2][2]) {
				if(!b[known][0] || !b[known][1]) addposs(true); 
			} else if(b[2][0] && b[2][1]){
				if(!b[known][2]) {
					if(!b[known][1]) {a[1] = true;}
					else if(!b[known][0]) {a[0] = true;}
					addposs(false);
				}
			} else if(b[2][0] && !b[known][0]) {a[0] = true; addposs(false);}
			else if(b[2][1] && !b[known][1]) {a[1] = true; addposs(false);}
			else {addposs(false); addposs(true);}
			//-----------
			cout << "Case " << cases << ": ";
			if(known == 0) {cout << s[0] << " ";}
			if(!sign[known] && sign[2]) printSet2();
			else printSet(true);
			cout << " ";
			if(known == 1) {cout << s[1] << " ";}
			cout << s[2] << endl;
		}
    }
}