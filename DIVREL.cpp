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
vvi graph(405);
bitset<405> vis;
int match[405];
int n, a[205];
int augment(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	for(auto v : graph[u]) {
		if(match[v] == - 1 || augment(match[v])) {
			match[u] = v; match[v] = u;
			return 1;
		}
	}
	return 0;
}
void edgeCover() {

}
int main() {
	SYNC;
	cin >> n;
	FOR0(i, n) cin >> a[i];
	sort(a,a+n);
	FOR0(i, n) FOR(j,i+1,n) {
		if(a[j]%a[i]==0) {
			graph[i].pb(j+n);
			graph[j+n].pb(i);
		}
	}
	FOR0(i, 2*n) match[i] = -1;
	int mcbm = 0;
	FOR0(i, n) {
		vis.reset();
		mcbm += augment(i);
	}
	cout << n - mcbm << endl;
	edgeCover();
}