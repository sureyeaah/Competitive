#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
using namespace std;
int main() {
	//ios::sync_with_stdio(false);
	int n,p,game = 1; string s1,s2;
	bool started = false;
	cin >> n >> p;
	while(n!=0 && p!= 0) {
		if(started) cout << endl;
		int r1,r2=0; float d1,d2=0;
		getline(cin, s1);
		FOR0(i,n) {
			getline(cin,s1);
		}
		FOR0(i,p) {
			getline(cin,s1);
			cin >> d1 >> r1;
			if(r1 > r2) {
				s2 = s1;
				d2 = d1;
				r2=r1;
			} else if(r2==r1 && d1 < d2) {
				s2 = s1;
				d2 = d1;
			}
			getline(cin,s1);
			FOR0(j,r1) {
				getline(cin,s1);
			}
		}
		cout << "RFP #" << game << endl << s2 << endl;
		game++;
		started = true;
		cin >> n >> p;
	}
}