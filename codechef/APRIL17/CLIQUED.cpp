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
#define INF ((ll)1e16)
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
typedef pair<ll, int> pli;
int main() {
	vector<vector<pair<int,ll > > > graph(100000 + 5);
	int t, n, k, m, s, a, b;
	ll dist[100000 + 5], x, c;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%lld%d%d",&n,&k,&x,&m,&s);
		FOR0(i,n+1) dist[i] = INF;
		dist[s] = 0;
		FOR0(i, n+1) graph[i].clear();
		while(m--) {
			scanf("%d%d%lld",&a,&b,&c);
			graph[a].pb(mp(b,c));
			graph[b].pb(mp(a,c));
		}
		priority_queue<pli, vector<pli>, greater<pli> > pq; pq.push(mp(0, s));
		while(!pq.empty()) {
			pli curr = pq.top(); pq.pop();
			ll d = curr.ff; int u = curr.ss;
			if(d > dist[u]) continue;
			repi(i, graph[u]) {
				int v = i->first; ll l = i->second;
				if(dist[v] <= dist[u]+l) continue;
				dist[v]=dist[u]+l;
				pq.push(mp(dist[v], v));
			}
		}
		ll cliqDist = *min_element(dist+1, dist+k+1);
		FOR(i,1,k+1) if(dist[i] > cliqDist+x) {
			dist[i] = cliqDist+x;
			pq.push(mp(dist[i],i));
		}
		while(!pq.empty()) {
			pli curr = pq.top(); pq.pop();
			ll d = curr.ff; int u = curr.ss;
			if(d > dist[u]) continue;
			repi(i, graph[u]) {
				int v = i->first; ll l = i->second;
				if(dist[v] <= dist[u]+l) continue;
				dist[v]=dist[u]+l;
				pq.push(mp(dist[v], v));
			}
		}
		FOR(i,1,n) printf("%lld ", dist[i]);
		printf("%lld\n", dist[n]);
	}
}