// dinic's algorithm
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
#define pb emplace_back
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
//--------------------
struct edge {
	int u, v;
	ll c, f;
	edge() { }
	edge(int _u, int _v, ll _c, ll _f = 0): u(_u), v(_v), c(_c), f(_f) { };
};
int n, m;
vector<edge> edges;
vvi g;
vi d, pt;

bool bfs(int s, int t) {
	queue<int> q; q.push(s);
	d.assign(n+1, INF);
	d[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for(int k : g[u]) {
			edge &e = edges[k];
			if(e.f < e.c && d[e.v] > d[e.u] + 1){
				d[e.v] = d[e.u] + 1;
				q.push(e.v);
			}
		}
	}
	return d[t] < INF;
}

ll dfs(int u, int t, ll flow = -1) {
	if(u == t || !flow) return flow;
	for(int &i = pt[u]; i < SZ(g[u]); i++) {
		edge &e = edges[g[u][i]], &oe=edges[g[u][i]^1];
		if(d[e.v] == d[e.u] + 1) {
			ll amt = e.c - e.f;
			if (flow != -1 && amt > flow) amt = flow;
			if(ll pushed = dfs(e.v,t,amt)) {
				e.f += pushed;
				oe.f -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

int main() {
	int a, b, c;
	scanf("%d %d", &n, &m);
	g.assign(n+1,vi()); edges.reserve(2*m+1);
	FOR0(i, m) {
		scanf("%d %d %d", &a, &b, &c);
		edges.pb(edge(a,b,c));
		g[a].pb(i<<1);
		edges.pb(edge(b,a,c));
		g[b].pb(i<<1|1);
	}
	ll ans = 0;
	while(bfs(1,n)) {
		pt.assign(n+1,0);
		while(ll flow = dfs(1,n)) ans += flow;
	}
	printf("%lld\n", ans);
}