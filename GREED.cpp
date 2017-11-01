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
#define MAXN 510
struct edge {
	int u,v,c,f;
	edge() {}
	edge(int U, int V, int C, int F): u(U), v(V), c(C), f(F) {}
};
int n;
vector<edge> edges;
vvi graph(MAXN);
vi par, ptr;
void addEdge(int u, int v, int c) {
	graph[u].pb(edges.size());
	edges.pb(edge(u,v,c,0));
	graph[v].pb(edges.size());
	edges.pb(edge(v,u,0,0));
}
int bfs(int S, int T) {
	par.assign(n+1, -1); ptr.assign(n+1, 0);
	queue<ii> q({mp(S,INF)}); par[S] = S;
	int ret = 0;
	while(!q.empty()) {
		ii curr = q.front(); q.pop();
		if(curr.ff == T) {ret = curr.ss; break;}
		for(int k: graph[curr.ff]) {
			edge &e = edges[k];
			if(par[e.v] == -1 && e.f < e.c) {
				par[e.v] = e.u;
				ptr[e.v] = k;
				q.push(mp(e.v, min(e.c-e.f, curr.ss)));
			}
		}
	}
	if(par[T] == -1) return 0;
	//augment
	int u = T;
	while(u != S) {
		edges[ptr[u]].f += ret;
		edges[ptr[u]^1].f -= ret;
		u = par[u];
	}
	return ret;
}
int flow(int S, int T) {
	int tot = 0;
	// reset
	for(auto & e : edges) e.f = 0;
	while(int cur = bfs(S, T))
		tot += cur;
	return tot;
}
int main() {
	SYNC;
	int t, cnt[MAXN], m, u, v, x, cards;
	cin >> t;
	while(t-- ) {
		cin >> cards;
		n = cards+2;
		int src = 0, snk = cards+1;
		edges.clear();
		FOR0(i, n+1) graph[i].clear();
		memset(cnt, 0, sizeof cnt);
		FOR0(i, cards) {
			cin >> x;
			cnt[x]++; 
		}
		FOR(i,1,cards+1) {
			if(cnt[i]) addEdge(src,i,cnt[i]-1);
			addEdge(i, snk, 1);
		}
		cin >> m;
		while(m--) {
			cin >> u >> v;
			addEdge(u,v,INF);
			addEdge(v,u,INF);
		}
		flow(src, snk);
		int ans = 0;
		for(auto & e : edges)
			if(e.u != src && e.v != snk && e.c > 0) ans += e.f;
		cout << ans << endl;
	}
}