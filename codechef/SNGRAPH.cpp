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
int t, n, m, u, v, par[100005], deg[100005], ans[100005], components;
vii edges;
vector<vii> ord(100005);
void init() {
	FOR0(i,n+1) par[i] = i;
	edges.clear();
	memset(deg,0,sizeof deg);
	components = n;
	FOR0(i, n) ord[i].clear();
}
int findSet(int i) {
	return par[i] == i ? i : (par[i] = findSet(par[i]));
}
bool sameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unite(int i, int j) {
	int x = findSet(i), y = findSet(j);
	if(x != y) {
		components--;
		par[x] = y;
	}
}	
int main() {
	SYNC;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		init();
		FOR0(i, m) {
			cin >> u >> v;
			deg[u]++; deg[v]++;
			edges.pb(mp(u, v));
		}
		for(ii & e : edges)
			ord[min(deg[e.ff], deg[e.ss])].pb(e);
		FORD(d,0,n) {
			ans[d] = components-1;
			for(ii & e : ord[d]) unite(e.ff, e.ss);
		}
		FOR0(i, n) cout << ans[i] << " ";
		cout << endl;
	}
}