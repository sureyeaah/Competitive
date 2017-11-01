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

int main() {
	int T, n, m, s, t, u, v, c, w, d, p, dist[10000+10], bestToll[10000+10];
	vector<vii> graph(10000+10);
	priority_queue< pair<ii,int> > pq;//-,+,+
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		FOR(i,1,n+1) graph[i].clear();
		FOR0(i, m) {
			scanf("%d%d%d", &u, &v, &c);
			graph[u].pb(mp(v, c));
		}
		FOR(i,1,n+1) dist[i] = INF;
		dist[s] = 0;
		FOR(i,1,n+1) bestToll[i] = 0;
		pq.push(mp(mp(0,0), s));
		while(!pq.empty()) {
			pair<ii, int> curr = pq.top(); pq.pop();
			d = -curr.first.first; c= curr.first.second; u = curr.second;
			repi(i, graph[u]) {
				v = (*i).first; w = (*i).second;
				if(max(c,w) > bestToll[v] && w+d <= p) {
					dist[v] = w+d;
					bestToll[v] = max(c,w);
					pq.push(mp(mp(-dist[v], bestToll[v]),v));
				} else if(max(c,w) == bestToll[v] && w+d < dist[v] && w+d <= p) {
					dist[v] = w+d;
					pq.push(mp(mp(-dist[v], bestToll[v]),v));
				}
			}
		}
		if(dist[t] <= p) cout << bestToll[t] << endl;
		else cout << -1 << endl;
	}
}