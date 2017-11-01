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
int n, s, k, sets, m, t, d, c, l, u, v, q, ds[10005], dt[10005];
vector<vii> graph(10005), transpose(10005);
void djikstra(int* dist, int src, vector<vii> &vec) {
	FOR(i,1,n+1) dist[i] = INF;
	dist[src] = 0;
	priority_queue <ii,vector<ii>,greater<ii> > pq;
	pq.push(mp(0,src));
	int edges = 0;
	while(!pq.empty()) {
		ii curr = pq.top(); pq.pop(); int u = curr.second;
		if(dist[u] < curr.first) continue;
		repi(i, vec[u]) {
			int v = (*i).first, len = (*i).second;
			if(dist[v] > dist[u]+len) {
				edges++;
				dist[v] = dist[u]+len;
				pq.push(mp(dist[v],v));
			}
		}
		if(edges == n-1) break;
	}
}
int main() {
	scanf("%d", &sets);
	while(sets--) {
		scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
		FOR0(i,n+1) graph[i].clear();
		FOR0(i,n+1) transpose[i].clear();
		FOR0(i, m) {
			scanf("%d%d%d",&d, &c, &l);
			graph[d].pb(mp(c,l));
			transpose[c].pb(mp(d,l));
		}
		djikstra(ds,s,graph);
		djikstra(dt,t,transpose);
		int ans = ds[t];
		FOR0(i, k) {
			scanf("%d%d%d",&u, &v, &q);
			ans = min(ans, q + min(ds[u]+dt[v], ds[v]+dt[u]));
		}
		if(ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}