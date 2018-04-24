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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	FOR(k,1,n+1) {
		if(n % k) continue;
		string block = "";
		int nk = n/k;
		FOR0(i, k) {
			int val = -1;
			for(int j = i; j < n; j+=k) {
				if(s[j] != '?') {
					if (val==-1) val = s[j]-'0';
					else if (val != s[j]-'0') {val = -2; break;} 
				}
			}
			if(val==-1) val = 0;
			else if(val == -2) break;
			block += '0' + val;
		}
		if(block.length() == k) {
			string ans = "";
			FOR0(i, nk) ans += block;
			cout << ans << endl;
			return 0;
		}
	}
}