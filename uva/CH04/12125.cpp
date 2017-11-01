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
struct edge {
	int u, v;
	int f, c;
	edge() {}
	edge(int _u, int _v, int _c, int _f): u(_u), v(_v), c(_c), f(_f) {}
};

int cases, n, x[101], y[101], src, snk;
double d;
vector<edge> edges;
vvi graph(202);
int ptr[202], dist[202];
void addEdge(int u, int v, int c) {
	edges.pb(edge(u,v,c,0));
	graph[u].pb(edges.size() - 1);	
	edges.pb(edge(v,u,0,0));
	graph[v].pb(edges.size() - 1);	
}
bool bfs() {
	queue<int> q({src});
	FOR0(i, src+1) dist[i] = INF;
	dist[src]=0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u == snk) break;
		for(int k: graph[u]) {
			edge & e = edges[k];
			if(e.f < e.c && dist[e.v] > dist[e.u]+1) {
				dist[e.v] = dist[e.u] + 1;
				q.emplace(e.v);
			}
		}
	}
	return dist[snk] < INF;
}
int dfs (int u, int flow = -1 ) {
	if(u == snk || !flow) return flow;
	for(int& i = ptr[u]; i < SZ(graph[u]); i++) {
		edge &e = edges[graph[u][i]], &oe = edges[graph[u][i]^1];
		if(dist[e.v] == dist[e.u] + 1) {
			int currFlow = e.c - e.f;
			if(flow != -1) currFlow = min(currFlow, flow);
			if(int pushed = dfs(e.v, currFlow)) {
				e.f += pushed;
				oe.f -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

int flow() {
	int ret = 0;
	while(bfs()) {
		memset(ptr, 0, sizeof ptr);
		while(int curr=dfs(src))
			ret += curr;
	}
	for(auto&e : edges) e.f=0;
	return ret;
}

int main() {
	SYNC;
	cin >> cases;
	while(cases--) {
		cin >> n >> d;
		src = n<<1;
		edges.clear();
		FOR0(i, src+1) graph[i].clear();
		int penguins = 0;
		FOR0(i, n) {
			int c;
			cin >> x[i] >> y[i] >> c;
			penguins += c;
			addEdge(src,i,c);
			cin >> c;
			addEdge(i,i+n,c);
		}
		FOR0(i, n) FOR0(j, i) {
			if(pow((ll)x[i]-x[j], 2) + pow((ll)y[i]-y[j], 2) <= (ll)(d*d)) {
				addEdge(i+n, j, INF);
				addEdge(j+n, i, INF);
			}
		}
		//for(edge&e : edges) cout << e.u << "->" << e.v << endl;
		vi ans;
		for(snk = 0; snk < n; snk++) {
			if(flow() == penguins) ans.pb(snk);
		}
		if(SZ(ans)) {
			cout << ans[0];
			for(int i = 1; i < SZ(ans); i++) cout << " " << ans[i];
			cout << endl;
		} else cout << -1 << endl;
	}
}