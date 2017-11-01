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
int n,m,p,a,b,match[50005];
bitset<50005> vis;
vvi g(50005);
int augment(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	FOR0(i, SZ(g[u])) {
		int v = g[u][i];
		if(match[v] == -1 || augment(match[v])) {
			match[v ] = u; return 1;
		}
	}
	return 0;	
}
int main() {
	SYNC;
	cin >> n >> m >> p;
	while(p--) {
		cin >> a >> b;
		g[a].pb(b);
	}
	FOR0(i, m+1) match[i] = -1;
	int ans = 0;
	FOR(i, 1, n+1) {
		vis.reset();
		ans += augment(i);
	}
	cout << ans << endl;
}