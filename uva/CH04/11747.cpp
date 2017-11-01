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
int n, m, u, v, w;
vector<pair<int,ii>> edges(25000 + 10);
int p[1000 + 10], r[1000 + 10];
vi ans;
void resetUF() {
	FOR0(i, n) p[i] = i;
	FOR0(i, n) r[i] = 0;
}
int findSet(int u) {
	return( (p[u] == u) ? u : (p[u] = findSet(p[u])) );
}
bool sameSet(int u, int v) {
	return findSet(u) == findSet(v);
}
void unionSet(int u, int v, int w) {
	int x = findSet(u), y = findSet(v);
	if(x != y) {
		if(r[x] > r[y]) p[y] = x;
		else {
			p[x] = y;
			if(r[x] == r[y]) r[y]++;
		}
	} else ans.pb(w);
}
int main() {
	while(scanf("%d%d",&n, &m) && (n || m)) {
		edges.clear();
		while(m--) {
			scanf("%d%d%d", &u, &v, &w);
			edges.pb(mp(w, mp(u, v)));
		}
		ans.clear();
		resetUF();
		sort(edges.begin(), edges.end());
		repi(i, edges) {
			int w = (*i).first, u = (*i).second.first, v = (*i).second.second;
			unionSet(u,v,w);
		}
		sort(ans.begin(), ans.end());
		if(ans.empty()) printf("forest\n");
		else {
			printf("%d",ans[0]);
			FOR(i,1,ans.size()) printf(" %d", ans[i]);
			printf("\n");
		}
	}
}