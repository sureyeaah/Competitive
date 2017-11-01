#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define val(c) ((c)-'0')

string rlz(string s) {
	int x = 0;
	while(x<s.length() && !val(s[x])) {x++;}
	if(x) s = s.substr(x,string::npos);
	return s;
}

string best(string s, int x) {
	FORD(i, 0, s.length()) {
		if(val(s[i])%3 == x) {
			if(!i) {
				s = s.substr(1,string::npos);
				return rlz(s);
			}
			else {
				s = s.substr(0,i)+s.substr(i+1,string::npos);
				return s;
			}
		}
	}
	return "";
}

int main() {
	string s, possible="", possible2="";
	cin >> s;
	int sum = 0;
	bool hasZeroes = false;
	FOR0(i, s.length()) if(!val(s[i])) hasZeroes = true;
	s = rlz(s);
	FOR0(i, s.length()) sum += val(s[i]);
	if(sum%3) {
		string ans1 = best(s, sum%3);
		string ans2 = best(best(s, 3-(sum%3)), 3-(sum%3));
		if(!ans1.length() && !ans2.length()) {if(hasZeroes) cout << 0 << endl; else cout << -1 << endl;}
		else if(ans1.length()>ans2.length()) cout << ans1 << endl;
		else cout << ans2 << endl;
	} else {
		if(s.length()) cout << s << endl;
		else cout << 0 << endl;
	}
}