#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
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
int t, n, m, a[205],match[205];
vvi graph(205);
bitset<205> vis;
int augment(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	for(int v: graph[u]) {
		if(match[v] == -1 || augment(match[v])) {
			match[v] = u; return 1;
		}
	}
	return 0;
}
int main() {
	SYNC;
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> n; FOR0(i, n) cin >> a[i];
		cin >> m; FOR0(i, m) cin >> a[i+n];
		FOR0(i, n+m) graph[i].clear();
		FOR0(i, n) FOR0(j, m) if((!a[i] && !a[j+n]) || (a[i] && a[j+n]%a[i] == 0)) {
			graph[i].pb(n+j);
			graph[j+n].pb(i);
		}
		// konig's
		FOR0(i, n+m) match[i] = -1;
		int mvc = 0;
		FOR0(i, n) {
			vis.reset();
			mvc += augment(i);
		}
		cout << printCase() << mvc << endl;
	}
}