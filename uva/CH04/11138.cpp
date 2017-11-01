#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case " << caseNum << ": "
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
int nuts, bolts, fits[501][501], match[501];
bitset<501> vis;
int augment(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	FOR0(i, nuts) {
		if(fits[u][i] && (match[i] == -1 || augment(match[i]))) {
			match[i] = u; return 1;
		}
	}
	return 0;
}
int main() {
	SYNC;
	int t;
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> bolts >> nuts;
		FOR0(i, bolts) FOR0(j, nuts) cin >> fits[i][j];
		int ans = 0;
		FOR0(i, nuts) match[i] = -1;
		FOR0(i, bolts) {
			vis.reset();
			ans += augment(i);
		}
		cout << printCase() <<  "a maximum of " << ans << " nuts and bolts can be fitted together" << endl;
	}
}