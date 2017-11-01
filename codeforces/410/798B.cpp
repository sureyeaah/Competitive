#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int solve(string &a, string &b) {
	if(a.length() != b.length()) return -1;
	int n = a.length();
	FOR0(i, n) {
		if(a[0] == b[i] && (a == b.substr(i,n-i)+b.substr(0,i))) return i;
	}
	return -1;
}
int main() {
	SYNC;
	int n;
	string s[51];
	cin >> n; FOR0(i, n) cin >> s[i];
	int ans = INF;
	FOR0(i, n) {
		int curr = 0;
		FOR0(j, n) {
			if(j==i) continue;
			int val = solve(s[i], s[j]);
			if(val == -1) {cout << -1 << endl; return 0;}
			else curr+=val;
		}
		ans = min(ans, curr);
	}
	cout << ans << endl;
}