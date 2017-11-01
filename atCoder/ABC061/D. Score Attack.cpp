#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
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
int n, m, a, b;
ll c;
ll dist[1000 + 5];
vector<vector<pair<int,ll> > > graph(1000 + 5);
int main() {
	SYNC;
	cin >> n >> m;
	FOR0(i, m) {
		cin >> a >> b >> c;
		graph[a].pb(mp(b,-c));
	}
	FOR(u,1,n+1) dist[u] = 100000000000000000; dist[1] = 0;
	FOR(j,0,n-1) {
		FOR(u,1,n+1) {
			repi(i, graph[u]) dist[i->ff] = min(dist[i->ff], dist[u]+(ll)i->ss);
		}
	}
	ll val = dist[n];
	FOR(j,0,n-1) {
		FOR(u,1,n+1) {
			repi(i, graph[u]) dist[i->ff] = min(dist[i->ff], dist[u]+(ll)i->ss);
		}
	}
	if(dist[n] != val) cout << "inf" << endl;
	else cout << -dist[n] << endl;
}