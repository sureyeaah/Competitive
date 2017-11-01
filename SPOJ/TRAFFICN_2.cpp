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
int n, s, k, sets, m, t, d, c, l, ds[20010];
vector<vii> graph(20010);
void djikstra(int* dist, int src) {
	FOR(i,1,(n+1) << 1|1) dist[i] = INF;
	dist[src] = 0;
	priority_queue <ii,vector<ii>,greater<ii> > pq;
	pq.push(mp(0,src));
	while(!pq.empty()) {
		ii curr = pq.top(); pq.pop(); int u = curr.second;
		if(dist[u] < curr.first) continue;
		repi(i, graph[u]) {
			int v = (*i).first, len = (*i).second;
			if(dist[v] > dist[u]+len) {
				dist[v] = dist[u]+len;
				pq.push(mp(dist[v],v));
			}
		}
	}
}
int main() {
	scanf("%d", &sets);
	while(sets--) {
		scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
		FOR0(i,(n+1) << 1) graph[i].clear();
		FOR0(i, m) {
			scanf("%d%d%d",&d, &c, &l);
			graph[d<<1].pb(mp(c<<1,l));
			graph[d<<1|1].pb(mp(c<<1|1,l));
		}
		while(k--) {
			scanf("%d%d%d",&d, &c, &l);
			graph[d<<1].pb(mp(c<<1|1,l));
			graph[c<<1].pb(mp(d<<1|1,l));
		}
		djikstra(ds,s<<1);
		int ans = min(ds[t << 1],ds[t << 1 | 1]);
		if(ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}