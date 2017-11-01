/*#include <iostream>
#include <map>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int suit(char c) {
	if(c=='S') return 0;
	if(c=='H') return 1;
	if(c=='D') return 2;
	if(c=='C') return 3;
}
char cs, cv; int csi, cvi, points1, points2;
int main() {
	//ios::sync_with_stdio(false);
	map<char, int> card;
card('A'] = 1;
card('K'] = 13;
card('Q'] = 12;
card('J'] = 11;
card('T'] = 10;
map<char, int> points;
points('A'] = 4;
points('K'] = 3;
points('Q'] = 2;
points('J'] = 1;
points('T'] = 0;
map<char, int> suit;
suit('S'] = 0;
suit('H'] = 1;
suit('D'] = 2;
suit('C'] = 3;
	while(true) {
		points1 = 0, points2 = 0;
		int cards[13][2], num[4] = {}; bool stopped[4] = {}, allStopped = true;
		//read and store as int
		cv = getchar(); if(cv==EOF) break; cs = getchar(); cin.ignore();
			csi = suit(cs]; 
			if(cv > '1' && cv <= '9') {
				cvi = cv - '0';
			} else {
				cvi = card(cv];
				points1 += points(cv];
			}
			num[csi]++;
			cards[0][0] = csi; cards[0][1] = cvi;
		FOR(i,1,13) {
			cv = getchar(); cs = getchar(); cin.ignore();
			csi = suit(cs]; 
			if(cv > '1' && cv <= '9') {
				cvi = cv - '0';
			} else {
				cvi = card(cv];
				points1 += points(cv];
			}
			num[csi]++;
			cards[i][0] = csi; cards[i][1] = cvi;
		}
		//calculate points1
		FOR0(i,13) {
			int currNum = num[cards[i][0]];
			if(cards[i][1] == 13) {
				if(currNum== 1) points1--; 
				else stopped[cards[i][0]] = true;
			} else if(cards[i][1] == 12) {
				if(currNum < 3) points1--;
				else stopped[cards[i][0]] = true;
			} else if(cards[i][1] == 11) {
				if(currNum < 4) points1--;
			} else if(cards[i][1] == 1) {
				stopped[cards[i][0]] = true;
			}
		}
		//calculate points2 and stopped
			FOR0(i,4) {
				if(num[i] == 2) points2++;
				else if(num[i] < 2) points2 += 2;
				if(!stopped[i]){allStopped = false;};
			}
		if(points1 >= 16 && allStopped) {
			cout << "BID NO-TRUMP" << endl;
		} else if((points1 + points2) < 14) {
			cout << "PASS" << endl;
		} else {
			int bid = 0;
			FOR(i,1,4) {
				if(num[i] > num[bid]) bid = i;
			}
			cout << "BID ";
			if(bid == 0) cout << "S";
			else if(bid == 1) cout << "H";
			else if(bid == 2) cout << "D";
			else cout << "C";
			cout << endl;
		}
	}
}*/






#include <iostream>
#include <map>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int suit(char c) {
	if(c=='S') return 0;
	if(c=='H') return 1;
	if(c=='D') return 2;
	if(c=='C') return 3;
}
int card(char c) {
	if(c == 'A') return 1;
	if(c == 'K') return 13;
	if(c == 'Q') return 12;
	if(c == 'J') return 11;
	if(c == 'T') return 10;
}
int points(char c) {
	if(c=='A') return 4;
	if(c=='K') return 3;
	if(c=='Q') return 2;
	if(c=='J') return 1;
	if(c=='T') return 0;
}
char cs, cv; int csi, cvi, points1, points2;
int main() {
	//ios::sync_with_stdio(false);
	while(true) {
		points1 = 0, points2 = 0;
		int cards[13][2], num[4] = {}; bool stopped[4] = {}, allStopped = true;
		//read and store as int
		cv = getchar(); if(cv==EOF) break; cs = getchar(); cin.ignore();
			csi = suit(cs); 
			if(cv > '1' && cv <= '9') {
				cvi = cv - '0';
			} else {
				cvi = card(cv);
				points1 += points(cv);
			}
			num[csi]++;
			cards[0][0] = csi; cards[0][1] = cvi;
		FOR(i,1,13) {
			cv = getchar(); cs = getchar(); cin.ignore();
			csi = suit(cs); 
			if(cv > '1' && cv <= '9') {
				cvi = cv - '0';
			} else {
				cvi = card(cv);
				points1 += points(cv);
			}
			num[csi]++;
			cards[i][0] = csi; cards[i][1] = cvi;
		}
		//calculate points1
		FOR0(i,13) {
			int currNum = num[cards[i][0]];
			if(cards[i][1] == 13) {
				if(currNum== 1) points1--; 
				else stopped[cards[i][0]] = true;
			} else if(cards[i][1] == 12) {
				if(currNum < 3) points1--;
				else stopped[cards[i][0]] = true;
			} else if(cards[i][1] == 11) {
				if(currNum < 4) points1--;
			} else if(cards[i][1] == 1) {
				stopped[cards[i][0]] = true;
			}
		}
		//calculate points2 and stopped
			FOR0(i,4) {
				if(num[i] == 2) points2++;
				else if(num[i] < 2) points2 += 2;
				if(!stopped[i]){allStopped = false;};
			}
		if(points1 >= 16 && allStopped) {
			cout << "BID NO-TRUMP" << endl;
		} else if((points1 + points2) < 14) {
			cout << "PASS" << endl;
		} else {
			int bid = 0;
			FOR(i,1,4) {
				if(num[i] > num[bid]) bid = i;
			}
			cout << "BID ";
			if(bid == 0) cout << "S";
			else if(bid == 1) cout << "H";
			else if(bid == 2) cout << "D";
			else cout << "C";
			cout << endl;
		}
	}
}